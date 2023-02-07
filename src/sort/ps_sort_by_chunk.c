/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_by_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:57:51 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:34:30 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rotate_closest_prev_to_top_b(t_ps *ps, int key)
{
	int		closest_prev;
	int		max;
	t_list	*node;

	if (!ps->b)
		return ;
	closest_prev = -1;
	max = ps_key(ps->b, 0);
	node = ps->b;
	while (node)
	{
		if (ps_key(node, 0) < key)
		{
			if (closest_prev == -1 || ps_key(node, 0) > closest_prev)
				closest_prev = ps_key(node, 0);
		}
		if (ps_key(node, 0) > max)
			max = ps_key(node, 0);
		node = node->next;
	}
	if (closest_prev == -1)
		closest_prev = max;
	ps_rotate_to_top_b(ps, closest_prev);
}

static void	ps_sort_chunk(t_ps *ps, int lo, int hi)
{
	int	index;
	int	key;

	index = ps_find_index_in_range(ps->a, lo, hi);
	while (index > -1)
	{
		key = ps_key(ps->a, index);
		ps_rotate_to_top_a(ps, key);
		ps_rotate_closest_prev_to_top_b(ps, key);
		ps_cmd(ps, PB);
		index = ps_find_index_in_range(ps->a, lo, hi);
	}
}

void	ps_sort_by_chunk(t_ps *ps, int chunk_size)
{
	int	chunk_len;
	int	chunk_i;
	int	lo;
	int	hi;

	chunk_len = ps->length / chunk_size;
	if (ps->length % chunk_size > 0)
		chunk_len++;
	chunk_i = 0;
	while (chunk_i < chunk_len)
	{
		lo = chunk_i * chunk_size;
		hi = (chunk_i + 1) * chunk_size - 1;
		if (hi > ps->length - 1)
			hi = ps->length - 1;
		ps_sort_chunk(ps, lo, hi);
		chunk_i++;
	}
	ps_rotate_to_top_b(ps, ps->length - 1);
	while (ft_lstsize(ps->b) > 0)
		ps_cmd(ps, PA);
}
