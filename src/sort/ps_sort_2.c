/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:13:58 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_2(t_ps *ps)
{
	int	i1;
	int	i2;

	ps_crash_exit_if(ft_lstsize(ps->a) != 2);
	i1 = ps_key(ps->a, 0);
	i2 = ps_key(ps->a, 1);
	if (i2 < i1)
		ps_cmd(ps, SA);
}
