/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:37:24 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/02 17:44:36 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_ps *ps)
{
	if (ps->length < 2)
		return ;
	else if (ps->length == 2)
		ps_sort_2(ps);
	else if (ps->length == 3)
		ps_sort_3(ps);
	else if (ps->length == 4 || ps->length == 5)
		ps_sort_3_more(ps);
	else
		ps_sort_radix(ps);
}
