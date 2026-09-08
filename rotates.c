/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:50:13 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/08 08:53:45 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return (0);
	tmp = stack->array[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = tmp;
	return (1);
}

void	ra(t_stack *stack_a)
{
	if (rotate(stack_a))
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack_b)
{
	if (rotate(stack_b))
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (rotate(stack_a) && rotate(stack_b))
		ft_putstr_fd("rr\n", 1);
}
