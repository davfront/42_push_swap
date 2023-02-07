/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:57 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 16:48:06 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_max(t_list *lst)
{
	int		size;
	int		max;
	int		i;

	size = ft_lstsize(lst);
	if (size < 1)
		ps_crash_exit();
	max = ps_key(lst, 0);
	i = 1;
	while (i < size)
	{
		if (max < ps_key(lst, i))
			max = ps_key(lst, i);
		i++;
	}
	return (max);
}
