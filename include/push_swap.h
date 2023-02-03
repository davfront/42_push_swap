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

typedef enum e_cmd {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_cmd;

// utils
void	ps_init(t_ps *ps);
void	ps_free(t_ps *ps);
void	ps_crash_exit();
void	ps_crash_exit_if(int condition);
void	ps_error_exit(t_ps *ps);
void	ps_error_exit_if(t_ps *ps, int condition);

// input
void	ps_check_duplicates(t_ps *ps);
void	ps_set_indexes(t_ps *ps);
void	ps_get_inputs(t_ps *ps, int argc, char **argv);

// cmd
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
void	ps_cmd(t_ps *ps, t_cmd cmd);

// list
int		ps_get(t_list *node, int offset);
int		ps_is_list_sorted(t_list *lst);
int		ps_is_list_sorted_with_offset(t_list *lst);
int		ps_find_pos_index(t_list *lst, int index);

// sort
void	ps_move_index_to_top_a(t_ps *ps, int index);
void	ps_sort_2(t_ps *ps);
void	ps_sort_3(t_ps *ps);
void	ps_sort_3_more(t_ps *ps);
void	ps_sort_radix(t_ps *ps);
void	ps_sort(t_ps *ps);

void	ps_print_ab(t_ps *ps);

#endif
