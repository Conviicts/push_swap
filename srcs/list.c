/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:59:03 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/26 03:42:07 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

void	print_list(t_stack *stack, char c)
{
	t_stack	*tmp;

	tmp = stack;
	printf("-------------%c--------------\n", c);
	while (tmp)
	{
		printf("[%d]\n", tmp->nb);
		tmp = tmp->next;
	}
	printf("---------------------------\n");
}

int		check_is_sorted(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->a;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->nb > tmp->next->nb)
				return (0);
			tmp = tmp->next;
		}
	}
	if (ps->b)
		return (0);
	return (1);
}

void	ft_add_bottom(t_stack **stack, int nb)
{
	t_stack	*tmp;
	t_stack	*elem;

	elem = *stack;
	tmp = malloc(sizeof(t_stack));
	tmp->nb = nb;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!elem)
		*stack = tmp;
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = tmp;
		tmp->prev = elem;
	}
}