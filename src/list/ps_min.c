/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:57 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 16:48:06 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_min(t_list *lst)
{
	int		size;
	int		min;
	int		i;

	size = ft_lstsize(lst);
	if (size < 1)
		ps_crash_exit();
	min = ps_key(lst, 0);
	i = 1;
	while (i < size)
	{
		if (min > ps_key(lst, i))
			min = ps_key(lst, i);
		i++;
	}
	return (min);
}
