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

void	ps_parse(int argc, char **argv, t_list	*a)
{
	char 	**strs;
	size_t	i;
	int		value;

	while (argc > 1)
	{
		strs = ft_split(argv[argc - 1], ' ');
		i = 0;
		while (strs[i])
		{
			ft_printf("%s\n", strs[i]);
			value = ft_atoi(strs[i]);
			ft_lstadd_back(&a, ft_lstnew(&value));
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
		free(strs);
		strs = NULL;
	}
}

void	ps_print_value(void *value)
{
	ft_printf("%i\n", value*);
}

int main(int argc, char **argv)
{
	t_list	*a;
	
	if (argc < 2)
		return (EXIT_SUCCESS);
	ps_parse(argc, argv, a);
	ft_lstiter(a, &ps_print_value);
	return (EXIT_SUCCESS);
}