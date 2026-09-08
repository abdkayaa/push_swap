/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 08:38:15 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/08 08:54:29 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->size <= 0)
		return ;
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = stack_b->array[0];
	stack_a->size++;
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->size--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->size <= 0)
		return ;
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->size++;
	stack_b->array[0] = stack_a->array[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->size--;
	ft_putstr_fd("pb\n", 1);
}
