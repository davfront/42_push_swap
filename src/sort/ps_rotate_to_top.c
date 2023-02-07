/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 11:26:36 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate_to_top_a(t_ps *ps, int key)
{
	int		index;
	t_cmd	cmd;

	index = ps_find_index(ps->a, key);
	ps_crash_exit_if(index == -1);
	cmd = RA;
	if (index > ft_lstsize(ps->a) / 2)
		cmd = RRA;
	while (ps_key(ps->a, 0) != key)
		ps_cmd(ps, cmd);
}

void	ps_rotate_to_top_b(t_ps *ps, int key)
{
	int		index;
	t_cmd	cmd;

	index = ps_find_index(ps->b, key);
	ps_crash_exit_if(index == -1);
	cmd = RB;
	if (index > ft_lstsize(ps->b) / 2)
		cmd = RRB;
	while (ps_key(ps->b, 0) != key)
		ps_cmd(ps, cmd);
}
