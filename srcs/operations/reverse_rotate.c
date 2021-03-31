/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:25:39 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 16:21:39 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *ps, t_stack *stack)
{
	t_stack *tmp;

	if (stack && stack->next)
	{
		tmp = get_last(ps->a);
		get_last(ps->a)->prev->next = NULL;
		tmp->next = ps->a;
		ps->a = tmp;
		if (ps->draw)
			printf("rra\n");
	}
}

void	rrb(t_ps *ps, t_stack *stack)
{
	int	first;
	int second;
	int third;

	if (stack && stack->next)
	{
		first = get_last(stack)->nb;
		second = stack->nb;
		third = stack->next->nb;
		stack->nb = first;
		stack->next->nb = second;
		stack->next->next->nb = third;
		if (ps->draw)
			printf("rrb\n");
	}
}