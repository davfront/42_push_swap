/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:20:40 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_find_index(t_list *lst, int key)
{
	int		size;
	int		index;

	size = ft_lstsize(lst);
	index = 0;
	while (index < size)
	{
		if (ps_key(lst, index) == key)
			return (index);
		index++;
	}
	return (-1);
}
