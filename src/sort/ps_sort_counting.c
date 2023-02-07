/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_counting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:09:04 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 15:21:10 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_rots	ps_compute_rots_before_pb(t_rots rots, int rev_a, int rev_b)
{
	t_rots	res;	

	res.ra = rots.ra * (1 - rev_a);
	res.rb = rots.rb * (1 - rev_b);
	res.rr = ps_imin(res.ra, res.rb);
	res.ra -= res.rr;
	res.rb -= res.rr;
	res.rra = rots.rra * rev_a;
	res.rrb = rots.rrb * rev_b;
	res.rrr = ps_imin(res.rra, res.rrb);
	res.rra -= res.rrr;
	res.rrb -= res.rrr;
	res.total = res.ra + res.rb + res.rr + res.rra + res.rrb + res.rrr;
	return (res);
}

static t_rots	ps_compute_min_rots_before_pb(t_rots rots)
{
	t_rots	res;
	t_rots	new_res;	

	res = ps_compute_rots_before_pb(rots, 0, 0);
	new_res = ps_compute_rots_before_pb(rots, 1, 0);
	if (res.total > new_res.total)
		res = new_res;
	new_res = ps_compute_rots_before_pb(rots, 0, 1);
	if (res.total > new_res.total)
		res = new_res;
	new_res = ps_compute_rots_before_pb(rots, 1, 1);
	if (res.total > new_res.total)
		res = new_res;
	return (res);
}

static t_rots	ps_count_rots_before_pb(t_ps *ps, int index_a)
{
	t_rots	rots;
	int		key_a;
	int		key_b;
	int		index_b;

	key_a = ps_key(ps->a, index_a);
	rots.ra = index_a;
	rots.rra = ft_lstsize(ps->a) - index_a;
	key_b = ps_closest_below(ps->b, key_a);
	index_b = ps_find_index(ps->b, key_b);
	rots.rb = index_b;
	rots.rrb = ft_lstsize(ps->b) - index_b;
	return (ps_compute_min_rots_before_pb(rots));
}

static void	ps_sort_counting_to_b(t_ps *ps)
{
	int		i;
	int		size_a;
	t_rots	min_rots;
	t_rots	rots;

	while (ft_lstsize(ps->a) > 3)
	{
		min_rots = ps_count_rots_before_pb(ps, 0);
		i = 0;
		size_a = ft_lstsize(ps->a);
		while (i < size_a)
		{
			if (i < min_rots.total || size_a - i < min_rots.total)
			{
				rots = ps_count_rots_before_pb(ps, i);
				if (rots.total < min_rots.total)
					min_rots = rots;
			}
			i++;
		}
		ps_cmd_rots(ps, min_rots);
		ps_cmd(ps, PB);
	}
}

void	ps_sort_counting(t_ps *ps)
{
	int		key;

	ps_crash_exit_if(ft_lstsize(ps->a) < 5);
	ps_cmd_n(ps, PB, 2);
	ps_sort_counting_to_b(ps);
	ps_sort_3(ps);
	while (ft_lstsize(ps->b) > 0)
	{
		key = ps_closest_above(ps->a, ps_key(ps->b, 0));
		ps_rotate_to_top_a(ps, key);
		ps_cmd(ps, PA);
	}
	ps_rotate_to_top_a(ps, 0);
}
