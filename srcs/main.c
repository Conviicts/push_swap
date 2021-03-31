/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:30:47 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 14:22:54 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_algo(t_ps *ps)
{
	(void)ps;
}

void	start(t_ps *ps)
{
	if (ps->size == 2)
	{
		if (ps->a->nb > ps->a->next->nb)
			sa(ps, ps->a);
	}
	else if (ps->size == 3)
		sort_3(ps);
	else if (ps->size == 4)
		sort_4(ps);
	else if (ps->size == 5)
		sort_5(ps);
	else if (ps->size <= 100)
		insertion_algo(ps);
}

int		main(int ac, char **av)
{
	t_ps	ps;
	
	if (ac < 2)
		return (1);
	if (!init_ps(&ps, av))
		return (1);
	ps.draw = 1;
	if (!check_is_sorted(&ps))
		start(&ps);
	print_list(ps.a, 'a');
}