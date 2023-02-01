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

void	ps_init(t_ps *ps)
{
	if (!ps)
		return ;
	ps->length = 0;
	ps->items = NULL;
	ps->a = NULL;
	ps->b = NULL;
}

void	ps_print_item(void *item)
{
	t_item	*item2;

	item2 = (t_item *)item;
	if (item2)
		ft_printf("  (%i, %i)\n", item2->value, item2->index);
}

void	ps_print_ab(t_ps *ps)
{
	ft_printf("<A (%i)>\n", ft_lstsize(ps->a));
	ft_lstiter(ps->a, ps_print_item);
	ft_printf("</A>\n");
	ft_printf("<B (%i)>\n", ft_lstsize(ps->b));
	ft_lstiter(ps->b, ps_print_item);
	ft_printf("</B>\n");
}

int	ps_get_input_length(int argc, char **argv)
{
	char	*s;
	int		i;
	int		len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		s = argv[i];
		while (*s)
		{
			if (s == argv[i] || (*s != ' ' && *(s - 1) == ' '))
				len++;
			s++;
		}
		i++;
	}
	return (len);
}

void	ps_get_input(t_ps *ps, int argc, char **argv)
{
	char	**strs;
	int		n;
	int		i;
	int		j;
	int		value;

	ps->length = ps_get_input_length(argc, argv);
	ps->items = ft_calloc(ps->length, sizeof(t_item));
	if (!ps->items)
		ps_error_exit();
	n = 0;
	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i], ' ');
		if (!strs)
			ps_error_exit();
		j = 0;
		while (strs[j])
		{
			// TODO: check is int (numeric, no overflow)
			value = ft_atoi(strs[j]);
			ps->items[n].value = value;
			ps->items[n].index = -1;
			ft_lstadd_back(&ps->a, ft_lstnew(&ps->items[n]));
			n++;
			ft_free((void **)&strs[j]);
			j++;
		}
		ft_free((void **)&strs);
		i++;
	}
}

#include <stdio.h>

int main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (EXIT_SUCCESS);
	ps_init(&ps);
	ps_get_input(&ps, argc, argv);
	ps_pb(&ps);
	ps_pb(&ps);
	ps_pb(&ps);
	ps_pb(&ps);
	ps_print_ab(&ps);
	ft_printf("rra\n");ps_rra(&ps);
	ps_print_ab(&ps);
	ft_printf("rra\n");ps_rra(&ps);
	ps_print_ab(&ps);
	ft_printf("rra\n");ps_rra(&ps);
	ps_print_ab(&ps);
	return (EXIT_SUCCESS);
}