/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:43:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 12:06:32 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_cmd_call(t_ps *ps, t_cmd cmd)
{
	if (cmd == SA)
		ps_sa(ps);
	else if (cmd == SB)
		ps_sb(ps);
	else if (cmd == SS)
		ps_ss(ps);
	else if (cmd == PA)
		ps_pa(ps);
	else if (cmd == PB)
		ps_pb(ps);
	else if (cmd == RA)
		ps_ra(ps);
	else if (cmd == RB)
		ps_rb(ps);
	else if (cmd == RR)
		ps_rr(ps);
	else if (cmd == RRA)
		ps_rra(ps);
	else if (cmd == RRB)
		ps_rrb(ps);
	else if (cmd == RRR)
		ps_rrr(ps);
}

static void	ps_cmd_print(t_cmd cmd)
{
	if (cmd == SA)
		ft_printf("sa\n");
	else if (cmd == SB)
		ft_printf("sb\n");
	else if (cmd == SS)
		ft_printf("ss\n");
	else if (cmd == PA)
		ft_printf("pa\n");
	else if (cmd == PB)
		ft_printf("pb\n");
	else if (cmd == RA)
		ft_printf("ra\n");
	else if (cmd == RB)
		ft_printf("rb\n");
	else if (cmd == RR)
		ft_printf("rr\n");
	else if (cmd == RRA)
		ft_printf("rra\n");
	else if (cmd == RRB)
		ft_printf("rrb\n");
	else if (cmd == RRR)
		ft_printf("rrr\n");
}

void	ps_cmd(t_ps *ps, t_cmd cmd)
{
	ps_cmd_call(ps, cmd);
	ps_cmd_print(cmd);
}

void	ps_cmd_n(t_ps *ps, t_cmd cmd, int n)
{
	while (n > 0)
	{
		ps_cmd(ps, cmd);
		n--;
	}
}
