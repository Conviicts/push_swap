/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:30:47 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 16:22:19 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves_start(t_ps *ps)
{
	t_stack	*tmp;
	t_stack	*first;
	int		moves;

	first = NULL;
	tmp = ps->a;
	moves = 0;
	while (tmp)
	{
		if (tmp->nb >= 0 && tmp->nb <= 19)
		{
			first = tmp;
			break;
		}
		moves++;
		tmp = tmp->next;
	}
	return (moves);
}

int	get_moves_end(t_ps *ps)
{
	t_stack	*tmp;
	t_stack	*last;
	int		moves;

	last = NULL;
	moves = 0;
	tmp = get_last(ps->a);
	while (tmp)
	{
		moves++;
		if (tmp->nb >= 0 && tmp->nb <= 19)
		{
			last = tmp;
			break;
		}
		tmp = tmp->prev;
	}
	return (moves);
}

void	insertion_algo(t_ps *ps)
{
	int first;
	int second;
	
	first = get_moves_start(ps);
	second = get_moves_end(ps);

	printf("%d\n", ps->size);
	if (first < second)
	{
		if (first <= ps->size / 2)
		{
			while (first-- > 0)
				ra(ps);
		}
		else
		{
			while (first-- > 0)
				rra(ps, ps->a);
		}
	}
	else
	{
		if (ps->size - second >= (ps->size / 2))
		{
			printf("%d\n", second);
			while (second-- > 0)
				rra(ps, ps->a);
		}
		else
		{
			while (second-- > 0)
				ra(ps);
		}
	}
	print_list(ps->a, 'a');
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
	{
		printf("a\n");
		return (1);
	}
	ps.draw = 1;
	if (!check_is_sorted(&ps))
		start(&ps);
	//print_list(ps.a, 'a');
}