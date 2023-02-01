/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 14:22:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error_exit(t_ps *ps)
{
	ps_free(ps);
	ft_putstr_fd("ERROR\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ps_error_exit_if(t_ps *ps, int condition)
{
	if (condition)
		ps_error_exit(ps);
}
