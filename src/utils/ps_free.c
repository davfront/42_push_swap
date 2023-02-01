/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:36:31 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 15:57:29 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_del_content(void *content)
{
	if (content)
		content = NULL;
}

void	ps_free(t_ps *ps)
{
	ft_free((void **)&ps->items);
	ft_lstclear(&ps->a, ps_del_content);
	ft_lstclear(&ps->b, ps_del_content);
	ps_init(ps);
}
