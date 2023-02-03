/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:57 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 16:48:06 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_get(t_list *node, int offset)
{
	t_item	*item;

	if (!node || !node->content || offset < 0 || offset > ft_lstsize(node) - 1)
		exit(EXIT_FAILURE);
	while (offset > 0)
	{
		node = node->next;
		offset--;
	}
	item = (t_item *)(node->content);
	return (item->index);
}
