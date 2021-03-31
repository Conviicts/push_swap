/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:31:15 by jode-vri          #+#    #+#             */
/*   Updated: 2021/03/31 14:34:02 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_ps
{
	t_stack	*a;
	t_stack	*b;
	int		draw;
	int		size;
	int		biggest;
	int		smallest;
	int		median;
}				t_ps;

int		init_ps(t_ps *ps, char **av);
void	ft_add_bottom(t_stack **stack, int nb);
int		check_is_sorted(t_ps *ps);
void	print_list(t_stack *stack, char c);
t_stack	*get_last(t_stack *stack);
void	find_median(t_ps *ps);
void 	find_biggest_nb(t_ps *ps, char stack);
void 	find_smallest_nb(t_ps *ps, char stack);
int 	get_moves_to_end(t_ps *ps, char stack);

void	sort_3(t_ps	*ps);
void	sort_4(t_ps	*ps);
void	sort_5(t_ps	*ps);


void	rra(t_ps *ps, t_stack *stack);
void	rrb(t_ps *ps, t_stack *stack);
void	sa(t_ps *ps, t_stack *stack);
void	sb(t_ps *ps, t_stack *stack);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	pb(t_ps *ps);
void	pa(t_ps *ps);

#endif