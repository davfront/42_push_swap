/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_list_sorted_with_offset.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:40:45 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_is_list_sorted_with_offset(t_list *lst)
{
	int		size;
	int		max_i;
	int		i;

	size = ft_lstsize(lst);
	if (size < 2)
		return (1);
	max_i = 0;
	i = 1;
	while (i < size)
	{
		if (ps_key(lst, i) > ps_key(lst, max_i))
			max_i = i;
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (ps_key(lst, i) > ps_key(lst, (i + 1) % size) && i != max_i)
			return (0);
		i++;
	}
	return (1);
}
