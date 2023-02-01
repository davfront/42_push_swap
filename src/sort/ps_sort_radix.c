/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 15:30:52 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_is_sorted(t_list	*lst)
{
	t_list	*node;

	node = lst;
	while (node->next)
	{
		if (ps_get_index(node) > ps_get_index(node->next))
			return (0);
		node = node->next;
	}
	return (1);
}

void	ps_sort_radix(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (!ps_is_sorted(ps->a))
	{
		j = 0;
		while (j < ps->length)
		{
			if ((ps_get_index(ps->a) >> i) & 1)
				ps_cmd(ps, RA);
			else
				ps_cmd(ps, PB);
			j++;
		}
		while (ft_lstsize(ps->b) > 0)
			ps_cmd(ps, PA);
		i++;
	}
}
