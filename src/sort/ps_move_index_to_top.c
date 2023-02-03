/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move_index_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/03 16:41:44 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_move_index_to_top_a(t_ps *ps, int index)
{
	int		pos;
	t_cmd	cmd;

	pos = ps_find_pos_index(ps->a, index);
	ps_crash_exit_if(pos == -1);
	cmd = RA;
	if (pos > ft_lstsize(ps->a) / 2)
		cmd = RRA;
	while (ps_get(ps->a, 0) != index)
		ps_cmd(ps, cmd);
}

void	ps_move_index_to_top_b(t_ps *ps, int index)
{
	int		pos;
	t_cmd	cmd;

	pos = ps_find_pos_index(ps->b, index);
	ps_crash_exit_if(pos == -1);
	cmd = RB;
	if (pos > ft_lstsize(ps->b) / 2)
		cmd = RRB;
	while (ps_get(ps->b, 0) != index)
		ps_cmd(ps, cmd);
}
