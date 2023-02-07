/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_index_in_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:57:51 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:22:54 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_find_index_in_range_top(t_list *lst, int lo, int hi)
{
	int	size;
	int	index;
	int	key;

	size = ft_lstsize(lst);
	index = 0;
	while (index < size)
	{
		key = ps_key(lst, index);
		if (key >= lo && key <= hi)
			return (index);
		index++;
	}
	return (-1);
}

static int	ps_find_index_in_range_bot(t_list *lst, int lo, int hi)
{
	int	size;
	int	index;
	int	key;

	size = ft_lstsize(lst);
	index = size - 1;
	while (index > -1)
	{
		key = ps_key(lst, index);
		if (key >= lo && key <= hi)
			return (index);
		index--;
	}
	return (-1);
}

int	ps_find_index_in_range(t_list *lst, int lo, int hi)
{
	int	top_index;
	int	bot_index;

	top_index = ps_find_index_in_range_top(lst, lo, hi);
	if (top_index <= 0)
		return (top_index);
	bot_index = ps_find_index_in_range_bot(lst, lo, hi);
	if (ft_lstsize(lst) - bot_index < top_index)
		return (bot_index);
	return (top_index);
}
