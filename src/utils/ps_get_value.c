/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:57 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 14:23:11 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_get_value(t_list	*node)
{
	t_item	*item;

	if (!node || !node->content)
		return (0);
	item = (t_item *)(node->content);
	return (item->value);
}
