/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 14:52:50 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_3(t_ps *ps)
{
	int	i1;
	int	i2;
	int	i3;

	if (ft_lstsize(ps->a) != 3)
		ps_error_exit(ps);
	i1 = ps_get_index(ps->a);
	i2 = ps_get_index(ps->a->next);
	i3 = ps_get_index(ps->a->next->next);
	if (i2 < i1 && i1 < i3)
		ps_cmd(ps, SA);
	else if (i3 < i2 && i2 < i1)
	{
		ps_cmd(ps, SA);
		ps_cmd(ps, RRA);
	}
	else if (i2 < i3 && i3 < i1)
		ps_cmd(ps, RA);
	else if (i1 < i3 && i3 < i2)
	{
		ps_cmd(ps, SA);
		ps_cmd(ps, RA);
	}
	else if (i3 < i1 && i1 < i2)
		ps_cmd(ps, RRA);
}
