/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:36:31 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 15:57:29 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_inputs_length(int argc, char **argv)
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

static int	ps_is_str_int(char *s)
{
	char	*int_max_str;
	char	*abs;
	int		is_neg;
	int		is_overflowed;

	if (!s || !*s)
		return (0);
	is_neg = (*s == '-');
	if ((*s == '-' || *s == '+') && ft_isdigit(*(s + 1)))
		s++;
	while (*s == '0' && ft_isdigit(*(s + 1)))
		s++;
	abs = s;
	while (ft_isdigit(*s))
		s++;
	if (*s)
		return (0);
	int_max_str = ft_itoa(INT_MAX);
	is_overflowed = (ft_strlen(abs) > ft_strlen(int_max_str) \
		|| (ft_strlen(abs) == ft_strlen(int_max_str) \
		&& ft_strncmp(abs, int_max_str, ft_strlen(int_max_str)) > is_neg));
	free(int_max_str);
	return (!is_overflowed);
}

static void	ps_set_input(t_ps *ps, char **str, t_item *item)
{
	int		value;
	void	*new_content;

	if (!str || !*str || !ps_is_str_int(*str))
		ps_error_exit(ps);
	value = ft_atoi(*str);
	(*item).value = value;
	(*item).key = -1;
	new_content = ft_lstnew(item);
	if (!new_content)
	{
		ft_free((void **)str);
		ps_error_exit(ps);
	}
	ft_lstadd_back(&ps->a, new_content);
	ft_free((void **)str);
}

static void	ps_parse_inputs(t_ps *ps, int argc, char **argv)
{
	char	**strs;
	int		n;
	int		i;
	int		j;

	ps->length = ps_get_inputs_length(argc, argv);
	ps->items = ft_calloc(ps->length, sizeof(t_item));
	ps_error_exit_if(ps, !ps->items);
	n = 0;
	i = 1;
	while (i < argc)
	{
		ps_error_exit_if(ps, !*argv[i]);
		strs = ft_split(argv[i], ' ');
		ps_error_exit_if(ps, !strs);
		j = 0;
		while (strs[j])
		{
			ps_set_input(ps, &strs[j], &ps->items[n]);
			n++;
			j++;
		}
		ft_free((void **)&strs);
		i++;
	}
}

void	ps_get_inputs(t_ps *ps, int argc, char **argv)
{
	ps_parse_inputs(ps, argc, argv);
	ps_check_duplicates(ps);
	ps_set_keys(ps);
}
