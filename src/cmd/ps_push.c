/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:12:46 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/31 17:00:01 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_push(t_list **lst1, t_list **lst2)
{
	t_list	*node;

	node = *lst1;
	*lst1 = (*lst1)->next;
	node->next = *lst2;
	*lst2 = node;
}

void	ps_pb(t_ps *ps)
{
	if (ps && ps->a)
		ps_push(&ps->a, &ps->b);
}

void	ps_pa(t_ps *ps)
{
	if (ps && ps->b)
		ps_push(&ps->b, &ps->a);
}
