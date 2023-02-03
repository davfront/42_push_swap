/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_by_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:57:51 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/03 17:20:34 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_chunk_top_pos(t_list *lst, int lo, int hi)
{
	int	size;
	int	pos;
	int	index;

	size = ft_lstsize(lst);
	pos = 0;
	while (pos < size)
	{
		index = ps_get(lst, pos);
		if (index >= lo && index <= hi)
			return (pos);
		pos++;
	}
	return (-1);
}

int	ps_chunk_bot_pos(t_list *lst, int lo, int hi)
{
	int	size;
	int	pos;
	int	index;

	size = ft_lstsize(lst);
	pos = size - 1;
	while (pos > -1)
	{
		index = ps_get(lst, pos);
		if (index >= lo && index <= hi)
			return (pos);
		pos--;
	}
	return (-1);
}


int	ps_chunk_pos(t_list *lst, int lo, int hi)
{
	int	top_pos;
	int	bot_pos;
	
	top_pos = ps_chunk_top_pos(lst, lo, hi);
	if (top_pos <= 0)
		return (top_pos);
	bot_pos = ps_chunk_bot_pos(lst, lo, hi);
	if (ft_lstsize(lst) - bot_pos < top_pos)
		return (bot_pos);
	return (top_pos);
}

void	ps_move_prev_to_top_b(t_ps *ps, int index)
{
	int		has_prev;
	int		prev_index;
	int		max_index;
	t_list	*node;

	if (!ps->b)
		return ;
	has_prev = 0;
	prev_index = 0;
	max_index = ps_get(ps->b, 0);
	node = ps->b;
	while (node)
	{
		if (ps_get(node, 0) < index)
		{
			if (!has_prev || ps_get(node, 0) > prev_index)
				prev_index = ps_get(node, 0);
			has_prev = 1;
		}
		if (ps_get(node, 0) > max_index)
			max_index = ps_get(node, 0);
		node = node->next;
	}
	if (!has_prev)
		prev_index = max_index;
	ps_move_index_to_top_b(ps, prev_index);
}

void	ps_sort_chunk(t_ps *ps, int lo, int hi)
{
	int	pos;
	int	index;

	pos = ps_chunk_pos(ps->a, lo, hi);
	while (pos > -1)
	{
		index = ps_get(ps->a, pos);
		ps_move_index_to_top_a(ps, index);
		ps_move_prev_to_top_b(ps, index);
		ps_cmd(ps, PB);
		pos = ps_chunk_pos(ps->a, lo, hi);
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