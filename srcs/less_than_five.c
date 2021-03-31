/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:39:30 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 15:00:08 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_ps	*ps)
{
	t_stack	*tmp;
	int		moves;
	
	find_biggest_nb(ps, 'a');
	moves = get_moves_to_end(ps, 'a');
	if (moves >= 1)
	{
		while (moves-- > 1)
			rra(ps, ps->a);
	}
	tmp = ps->a;
	if (tmp->nb > tmp->next->nb)
		sa(ps, ps->a);
}

void	sort_4(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->a;
	find_biggest_nb(ps, 'a');
	find_smallest_nb(ps, 'a');
	while (tmp && tmp->nb != ps->smallest)
		ra(ps);
	pb(ps);
	sort_3(ps);
	pa(ps);
}

void	sort_5(t_ps *ps)
{
	t_stack	*tmp;
	int		i;
	
	i = 0;
	find_median(ps);
	while (i < ps->size)
	{
		if (ps->a->nb < ps->median)
			pb(ps);
		else
			ra(ps);
		i++;
	}
	sort_3(ps);
	tmp = ps->b->next;
	if (ps->b->nb < tmp->nb)
		sb(ps, ps->b);
	pa(ps);
	pa(ps);
}
