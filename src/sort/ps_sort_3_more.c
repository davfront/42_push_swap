/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_3_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:27:43 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_3_more(t_ps *ps)
{
	ps_crash_exit_if(ft_lstsize(ps->a) < 3);
	while (ft_lstsize(ps->a) > 3)
	{
		ps_rotate_to_top_a(ps, ft_lstsize(ps->b));
		ps_cmd(ps, PB);
	}
	ps_sort_3(ps);
	while (ft_lstsize(ps->b) > 0)
		ps_cmd(ps, PA);
}
