/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmd_rots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:09:04 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 14:42:38 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_cmd_rots(t_ps *ps, t_rots rots)
{
	ps_cmd_n(ps, RR, rots.rr);
	ps_cmd_n(ps, RA, rots.ra);
	ps_cmd_n(ps, RB, rots.rb);
	ps_cmd_n(ps, RRR, rots.rrr);
	ps_cmd_n(ps, RRA, rots.rra);
	ps_cmd_n(ps, RRB, rots.rrb);
}
