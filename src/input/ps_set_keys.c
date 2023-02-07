/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:42:26 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:12:30 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_set_keys(t_ps *ps)
{
	int	i;
	int	j;
	int	order;

	i = 0;
	while (i < ps->length)
	{
		order = 0;
		j = 0;
		while (j < ps->length)
		{
			if (j != i && ps->items[j].value < ps->items[i].value)
				order++;
			j++;
		}
		ps->items[i].key = order;
		i++;
	}
}
