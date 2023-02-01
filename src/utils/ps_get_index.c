/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:57 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 14:21:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_get_index(t_list	*node)
{
	t_item	*item;

	if (!node || !node->content)
		return (-1);
	item = (t_item *)(node->content);
	return (item->index);
}
