/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:42:26 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 12:57:28 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_check_duplicates(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->length - 1)
	{
		j = i + 1;
		while (j < ps->length)
		{
			if (ps->items[j].value == ps->items[i].value)
				ps_error_exit(ps);
			j++;
		}
		i++;
	}
}
