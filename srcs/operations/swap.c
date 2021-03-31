/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 01:46:43 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 14:24:18 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps, t_stack *stack)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->nb;
		stack->nb = stack->next->nb;
		stack->next->nb = tmp;
		if (ps->draw)
			printf("sa\n");
	}
}

void	sb(t_ps *ps, t_stack *stack)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->nb;
		stack->nb = stack->next->nb;
		stack->next->nb = tmp;
		if (ps->draw)
			printf("sb\n");
	}
}