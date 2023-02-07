/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_closest_below.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:57 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 14:17:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_closest_below(t_list *lst, int key)
{
	int		size;
	int		cb;
	int		i;

	size = ft_lstsize(lst);
	if (size < 1)
		ps_crash_exit();
	cb = -1;
	i = 0;
	while (i < size)
	{
		if (ps_key(lst, i) < key && (cb == -1 || ps_key(lst, i) > cb))
			cb = ps_key(lst, i);
		i++;
	}
	if (cb == -1)
		return (ps_max(lst));
	return (cb);
}
