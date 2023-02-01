/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:32:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 14:22:40 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_item {
	int		index;
	int		value;
}			t_item;

typedef struct s_ps {
	int		length;
	t_item	*items;
	t_list	*a;
	t_list	*b;
}			t_ps;

void	ps_error_exit();

// commands
void	ps_sa(t_ps *ps);
void	ps_sb(t_ps *ps);
void	ps_ss(t_ps *ps);
void	ps_pa(t_ps *ps);
void	ps_pb(t_ps *ps);
void	ps_ra(t_ps *ps);
void	ps_rb(t_ps *ps);
void	ps_rr(t_ps *ps);
void	ps_rra(t_ps *ps);
void	ps_rrb(t_ps *ps);
void	ps_rrr(t_ps *ps);

# endif
