/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:49:47 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 17:08:08 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_cmd_str(t_ps *ps, char *str)
{
	if (!ft_strncmp(str, "sa\n", ft_strlen("sa\n") + 1))
		ps_cmd_call(ps, SA);
	else if (!ft_strncmp(str, "sb\n", ft_strlen("sb\n") + 1))
		ps_cmd_call(ps, SB);
	else if (!ft_strncmp(str, "ss\n", ft_strlen("ss\n") + 1))
		ps_cmd_call(ps, SS);
	else if (!ft_strncmp(str, "pa\n", ft_strlen("pa\n") + 1))
		ps_cmd_call(ps, PA);
	else if (!ft_strncmp(str, "pb\n", ft_strlen("pb\n") + 1))
		ps_cmd_call(ps, PB);
	else if (!ft_strncmp(str, "ra\n", ft_strlen("ra\n") + 1))
		ps_cmd_call(ps, RA);
	else if (!ft_strncmp(str, "rb\n", ft_strlen("rb\n") + 1))
		ps_cmd_call(ps, RB);
	else if (!ft_strncmp(str, "rr\n", ft_strlen("rr\n") + 1))
		ps_cmd_call(ps, RR);
	else if (!ft_strncmp(str, "rra\n", ft_strlen("rra\n") + 1))
		ps_cmd_call(ps, RRA);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen("rrb\n") + 1))
		ps_cmd_call(ps, RRB);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen("rrr\n") + 1))
		ps_cmd_call(ps, RRR);
	else
		return (0);
	return (1);
}

static void	ps_read_cmds(t_ps *ps)
{
	char	*cmd_str;

	cmd_str = ft_gnl(STDIN_FILENO);
	while (cmd_str)
	{
		if (!ps_cmd_str(ps, cmd_str))
		{
			ft_free((void **)&cmd_str);
			ps_error_exit(ps);
		}
		cmd_str = ft_gnl(STDIN_FILENO);
	}
	ft_free((void **)&cmd_str);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (EXIT_SUCCESS);
	ps_init(&ps);
	ps_get_inputs(&ps, argc, argv);
	ps_read_cmds(&ps);
	if (ps_is_list_sorted(ps.a) && ft_lstsize(ps.a) == ps.length)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ps_free(&ps);
	return (EXIT_SUCCESS);
}
