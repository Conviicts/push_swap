/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:14:23 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 14:23:21 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	
	if (ps->b)
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp2 = ps->a;
		ps->a = tmp;
		tmp->next = tmp2;
		if (ps->draw)
			printf("pa\n");
	}
}

void	pb(t_ps *ps)
{
	t_stack	*tmp;
	
	if (ps->a)
	{
		tmp = ps->a;
		ps->a = ps->a->next;
		tmp->next = ps->b;
		ps->b = tmp;
		if (ps->draw)
			printf("pb\n");
	}
}