/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:12:46 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/31 17:20:48 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_swap(t_list **lst)
{
	t_list	*node1;
	t_list	*node2;

	if (*lst && ft_lstsize(*lst) >= 2)
	{
		node1 = *lst;
		node2 = node1->next;
		node1->next = node2->next;
		node2->next = node1;
		*lst = node2;
	}
}

void	ps_sa(t_ps *ps)
{
	if (ps && ps->a)
		ps_swap(&ps->a);
}

void	ps_sb(t_ps *ps)
{
	if (ps && ps->b)
		ps_swap(&ps->b);
}

void	ps_ss(t_ps *ps)
{
	ps_sa(ps);
	ps_sb(ps);
}
