/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_pos_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/02 16:58:27 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_find_pos_index(t_list *lst, int index)
{
	int		size;
	int		pos;

	size = ft_lstsize(lst);
	pos = 0;
	while (pos < size)
	{
		if (ps_get(lst, pos) == index)
			return (pos);
		pos++;
	}
	return (-1);
}
