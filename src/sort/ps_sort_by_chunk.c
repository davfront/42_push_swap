/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_by_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:57:51 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/04 01:35:03 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_move_prev_to_top_b(t_ps *ps, int index)
{
	int		prev_index;
	int		max_index;
	t_list	*node;

	if (!ps->b)
		return ;
	prev_index = -1;
	max_index = ps_get(ps->b, 0);
	node = ps->b;
	while (node)
	{
		if (ps_get(node, 0) < index)
		{
			if (prev_index == -1 || ps_get(node, 0) > prev_index)
				prev_index = ps_get(node, 0);
		}
		if (ps_get(node, 0) > max_index)
			max_index = ps_get(node, 0);
		node = node->next;
	}
	if (prev_index == -1)
		prev_index = max_index;
	ps_move_index_to_top_b(ps, prev_index);
}

static void	ps_sort_chunk(t_ps *ps, int lo, int hi)
{
	int	pos;
	int	index;

	pos = ps_find_pos_range(ps->a, lo, hi);
	while (pos > -1)
	{
		index = ps_get(ps->a, pos);
		ps_move_index_to_top_a(ps, index);
		ps_move_prev_to_top_b(ps, index);
		ps_cmd(ps, PB);
		pos = ps_find_pos_range(ps->a, lo, hi);
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
	ps_move_index_to_top_b(ps, ps->length - 1);
	while (ft_lstsize(ps->b) > 0)
		ps_cmd(ps, PA);
}
