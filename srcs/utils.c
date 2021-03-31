/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:51:47 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/29 10:16:37 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_param(char *s)
{
	int		i;
	long	nb;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
		if (s[i] < '0' || s[i++] > '9')
			return (0);
	nb = ft_atoi(s);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	i = -1;
	return (1);
}

static int	is_in_double(char **av)
{
	int 	i;
	int		j;
	long	nb;
	long 	nb2;

	i = -1;
	while (av[++i])
	{
		nb = ft_atoi(av[i]);
		j = i;
		while (av[++j])
		{
			nb2 = ft_atoi(av[j]);
			if (nb == nb2)
				return (1);
		}
	}
	return (0);
}

int			init_ps(t_ps *ps, char **av)
{
	int	i;
	int	nb;

	i = 0;
	ft_bzero(ps, sizeof(t_ps));
	while (av[++i])
	{
		if (!is_valid_param(av[i]))
			return (0);
		if (is_in_double(av))
			return (0);
		nb = (int)ft_atoi(av[i]);
		ft_add_bottom(&ps->a, nb);
		ps->size++;
	}
	ps->b = malloc(sizeof(t_stack));
	ps->b = NULL;
	return (1);
}
