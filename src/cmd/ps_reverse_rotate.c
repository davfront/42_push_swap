/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:12:46 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/31 17:20:43 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_reverse_rotate(t_list **lst)
{
	t_list	*first;
	t_list	*before_last;
	t_list	*last;
	int		size;

	if (!*lst)
		return ;
	size = ft_lstsize(*lst);
	if (ft_lstsize(*lst) < 2)
		return ;
	first = *lst;
	before_last = ft_lst_by_index(*lst, size - 2);
	last = before_last->next;
	*lst = last;
	last->next = first;
	before_last->next = NULL;
}

void	ps_rra(t_ps *ps)
{
	if (ps && ps->a)
		ps_reverse_rotate(&ps->a);
}

void	ps_rrb(t_ps *ps)
{
	if (ps && ps->b)
		ps_reverse_rotate(&ps->b);
}

void	ps_rrr(t_ps *ps)
{
	ps_rra(ps);
	ps_rrb(ps);
}
