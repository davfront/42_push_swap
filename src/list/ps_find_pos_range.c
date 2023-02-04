/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_pos_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:57:51 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/04 01:37:24 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_find_pos_range_top(t_list *lst, int lo, int hi)
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

static int	ps_find_pos_range_bot(t_list *lst, int lo, int hi)
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

int	ps_find_pos_range(t_list *lst, int lo, int hi)
{
	int	top_pos;
	int	bot_pos;

	top_pos = ps_find_pos_range_top(lst, lo, hi);
	if (top_pos <= 0)
		return (top_pos);
	bot_pos = ps_find_pos_range_bot(lst, lo, hi);
	if (ft_lstsize(lst) - bot_pos < top_pos)
		return (bot_pos);
	return (top_pos);
}
