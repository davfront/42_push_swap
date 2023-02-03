/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:37:24 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/03 17:30:01 by dapereir         ###   ########.fr       */
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
	else if (ps->length <= 20)
		ps_sort_3_more(ps);
	else if (ps->length <= 200)
		ps_sort_by_chunk(ps, ps->length / 5);
	else if (ps->length <= 1000)
		ps_sort_by_chunk(ps, ps->length / 11);
	else
		ps_sort_radix(ps);
}
