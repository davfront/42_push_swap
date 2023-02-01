/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:36:31 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 15:57:29 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_item(void *item)
{
	t_item	*item2;

	item2 = (t_item *)item;
	if (item2)
		ft_printf("\t%i\t%i\n", item2->index, item2->value);
}

void	ps_print_ab(t_ps *ps)
{
	ft_printf("<A (%i)>\n", ft_lstsize(ps->a));
	ft_lstiter(ps->a, ps_print_item);
	ft_printf("<B (%i)>\n", ft_lstsize(ps->b));
	ft_lstiter(ps->b, ps_print_item);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (EXIT_SUCCESS);
	ps_init(&ps);
	ps_get_inputs(&ps, argc, argv);
	ps_check_duplicates(&ps);
	ps_set_indexes(&ps);
	// ps_pb(&ps);
	// ps_pb(&ps);
	// ps_pb(&ps);
	// ps_pb(&ps);
	// ps_print_ab(&ps);
	// ft_printf("rra\n");ps_rra(&ps);
	// ps_print_ab(&ps);
	// ft_printf("rra\n");ps_rra(&ps);
	// ps_print_ab(&ps);
	// ft_printf("rra\n");ps_rra(&ps);
	ps_print_ab(&ps);
	ps_free(&ps);
	return (EXIT_SUCCESS);
}
