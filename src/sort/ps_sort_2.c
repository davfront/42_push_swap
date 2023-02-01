/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/01 15:28:39 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_2(t_ps *ps)
{
	int	i1;
	int	i2;

	if (ft_lstsize(ps->a) != 3)
		ps_error_exit(ps);
	i1 = ps_get_index(ps->a);
	i2 = ps_get_index(ps->a->next);
	if (i2 < i1)
		ps_cmd(ps, SA);
}
