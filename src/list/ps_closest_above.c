/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_closest_above.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:57 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/07 14:17:00 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_closest_above(t_list *lst, int key)
{
	int		size;
	int		ca;
	int		i;

	size = ft_lstsize(lst);
	if (size < 1)
		ps_crash_exit();
	ca = -1;
	i = 0;
	while (i < size)
	{
		if (ps_key(lst, i) > key && (ca == -1 || ps_key(lst, i) < ca))
			ca = ps_key(lst, i);
		i++;
	}
	if (ca == -1)
		return (ps_min(lst));
	return (ca);
}
