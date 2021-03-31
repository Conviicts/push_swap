/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:41:48 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 14:19:48 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int len)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (i < (len - 1))
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

void		find_median(t_ps *ps)
{
	t_stack *tmp;
	int		*array;
	int		quarter;
	int		i;

	tmp = ps->a;
	array = malloc(sizeof(int) * (ps->size + 1));
	quarter = ps->size / 4;
	i = -1;
	while (tmp)
	{
		array[++i] = tmp->nb;
		tmp = tmp->next;
	}
	sort_array(array, ps->size);
	ps->median = array[quarter * 2];
	free(array);
}

void 		find_biggest_nb(t_ps *ps, char stack)
{
	t_stack	*tmp;

	if (stack == 'a')
		tmp = ps->a;
	else
		tmp = ps->b;
	ps->biggest = tmp->nb;
	while (tmp)
	{
		if (tmp->nb > ps->biggest)
			ps->biggest = tmp->nb;
		tmp = tmp->next;
	}
}

void	 	find_smallest_nb(t_ps *ps, char stack)
{
	t_stack	*tmp;

	if (stack == 'a')
		tmp = ps->a;
	else
		tmp = ps->b;
	ps->smallest = ps->biggest;
	while (tmp)
	{
		if (tmp->nb < ps->smallest)
			ps->smallest = tmp->nb;
		tmp = tmp->next;
	}
}

int 		get_moves_to_end(t_ps *ps, char stack)
{
	t_stack	*tmp;
	int		moves;

	if (stack == 'a')
		tmp = get_last(ps->a);
	else
		tmp = get_last(ps->b);
	moves = 0;
	if (tmp)
	{
		while (tmp->nb != ps->biggest)
		{
			moves++;
			tmp = tmp->prev;
		}
		moves++;
	}
	return (moves);
}

