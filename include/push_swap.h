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
	int		key;
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

typedef struct s_rots {
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}			t_rots;

// int
int		ps_imin(int a, int b);

// utils
void	ps_init(t_ps *ps);
void	ps_free(t_ps *ps);
void	ps_crash_exit(void);
void	ps_crash_exit_if(int condition);
void	ps_error_exit(t_ps *ps);
void	ps_error_exit_if(t_ps *ps, int condition);

// input
void	ps_check_duplicates(t_ps *ps);
void	ps_set_keys(t_ps *ps);
void	ps_get_inputs(t_ps *ps, int argc, char **argv);

// print
void	ps_print_ab(t_ps *ps);

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
void	ps_cmd_n(t_ps *ps, t_cmd cmd, int n);
void	ps_cmd_rots(t_ps *ps, t_rots rots);

// list
int		ps_key(t_list *node, int index);
int		ps_is_list_sorted(t_list *lst);
int		ps_is_list_sorted_with_offset(t_list *lst);
int		ps_find_index(t_list *lst, int key);
int		ps_find_index_in_range(t_list *lst, int lo, int hi);
int		ps_min(t_list *lst);
int		ps_max(t_list *lst);
int		ps_closest_below(t_list *lst, int key);
int		ps_closest_above(t_list *lst, int key);

// sort
void	ps_rotate_to_top_a(t_ps *ps, int key);
void	ps_rotate_to_top_b(t_ps *ps, int key);
void	ps_sort_2(t_ps *ps);
void	ps_sort_3(t_ps *ps);
void	ps_sort_3_more(t_ps *ps);
void	ps_sort_radix(t_ps *ps);
void	ps_sort_by_chunk(t_ps *ps, int chunk_size);
void	ps_sort_counting(t_ps *ps);
void	ps_sort(t_ps *ps);

#endif
