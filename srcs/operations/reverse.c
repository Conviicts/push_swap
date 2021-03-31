/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:39:18 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 14:25:44 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	t_stack		*stack;
	int			tmp;

	if (ps->a)
	{
		stack = ps->a;
		tmp = ps->a->nb;
		while (stack->next)
		{
			stack->nb = stack->next->nb;
			stack = stack->next;
		}
		get_last(ps->a)->nb = tmp;
		if (ps->draw)
			printf("ra\n");
	}
}

void	rb(t_ps *ps)
{
	t_stack		*stack;
	int			tmp;

	if (ps->b)
	{
		stack = ps->b;
		tmp = ps->b->nb;
		while (stack->next)
		{
			stack->nb = stack->next->nb;
			stack = stack->next;
		}
		get_last(ps->b)->nb = tmp;
		if (ps->draw)
			printf("rb\n");
	}
}