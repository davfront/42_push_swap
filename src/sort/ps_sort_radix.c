/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:13:58 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_radix(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (!ps_is_list_sorted(ps->a))
	{
		j = 0;
		while (j < ps->length)
		{
			if ((ps_key(ps->a, 0) >> i) & 1)
				ps_cmd(ps, RA);
			else
				ps_cmd(ps, PB);
			j++;
		}
		while (ft_lstsize(ps->b) > 0)
			ps_cmd(ps, PA);
		i++;
	}
}
