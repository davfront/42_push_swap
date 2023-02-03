/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_list_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/02 16:02:23 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_is_list_sorted(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node->next)
	{
		if (ps_get(node, 0) > ps_get(node, 1))
			return (0);
		node = node->next;
	}
	return (1);
}
