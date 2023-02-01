/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:12:46 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/31 16:59:58 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rotate(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (*lst && ft_lstsize(*lst) >= 2)
	{
		first = *lst;
		last = ft_lstlast(*lst);
		*lst = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	ps_ra(t_ps *ps)
{
	if (ps && ps->a)
		ps_rotate(&ps->a);
}

void	ps_rb(t_ps *ps)
{
	if (ps && ps->b)
		ps_rotate(&ps->b);
}

void	ps_rr(t_ps *ps)
{
	ps_ra(ps);
	ps_rb(ps);
}
