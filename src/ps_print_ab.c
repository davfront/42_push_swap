/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:39:42 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/02 17:42:14 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ps_print_item(t_list *lst, int i, int size)
{
	int		lst_size;
	int		node_index;
	t_list	*node;
	t_item	*item;

	lst_size = ft_lstsize(lst);
	node_index = i - size + lst_size;
	if (node_index >= 0)
	{
		node = ft_lst_by_index(lst, node_index);
		item = (t_item *)(node->content);
		ft_printf("\t%i\t%i", item->index, item->value);
	}
	else
		ft_printf("\t\t");
}

void	ps_print_ab(t_ps *ps)
{
	int		size;
	int		i;

	size = ft_lstsize(ps->a);
	if (size < ft_lstsize(ps->b))
		size = ft_lstsize(ps->b);
	ft_printf("--------------------------------------------------\n");
	i = 0;
	while (i < size)
	{
		ps_print_item(ps->a, i, size);
		ft_printf("\t");
		ps_print_item(ps->b, i, size);
		ft_printf("\n");
		i++;
	}
	ft_printf("\t----------------\t------------------\n");
	ft_printf("\tA (%i)\t\t\tB (%i)\n", ft_lstsize(ps->a), ft_lstsize(ps->b));
	ft_printf("--------------------------------------------------\n");
}