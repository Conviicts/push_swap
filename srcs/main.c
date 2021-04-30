/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:30:47 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 22:08:07 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves_start(t_ps *ps, char c)
{
	t_stack	*tmp;
	t_stack	*first;
	int		moves;

	first = NULL;
	if (c == 'a')
		tmp = ps->a;
	else
		tmp = ps->b;
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

int	get_moves_end(t_ps *ps, char c)
{
	t_stack	*tmp;
	t_stack	*last;
	int		moves;

	last = NULL;
	moves = 0;
	if (c == 'a')
		tmp = get_last(ps->a);
	else
		tmp = get_last(ps->b);
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

int		get_moves_minus(t_ps *ps)
{
	int moves;
	int minus;
	t_stack	*tmp;

	tmp = ps->a;
	moves = 0;
	minus = ps->a->nb;
	while (tmp)
	{
		if (ps->a->nb < minus)
		{
			minus = ps->a->nb;
			moves++;
		}
		tmp = tmp->next;
	}
	return (moves);
}

void	truc2(t_ps *ps)
{
	int first;
	int second;
	
	first = get_moves_start(ps, 'b');
	second = get_moves_end(ps, 'b');
	
	printf("moves %d", first);
	pb(ps);
	print_list(ps->b, 'b');
}

void	insertion_algo(t_ps *ps)
{
	int first;
	int second;
	
	first = get_moves_start(ps, 'a');
	second = get_moves_end(ps, 'a');

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
	truc2(ps);
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
	//print_list(ps.a, 'a');
}