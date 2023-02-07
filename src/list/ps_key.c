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

int	ps_key(t_list *node, int index)
{
	t_item	*item;

	if (!node || !node->content || index < 0 || index > ft_lstsize(node) - 1)
		ps_crash_exit();
	while (index > 0)
	{
		node = node->next;
		index--;
	}
	item = (t_item *)(node->content);
	return (item->key);
}
