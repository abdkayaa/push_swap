/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   swaps.c                                              :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/07 18:33:22 by okaymazo            #+#    #+#           */
/*   Updated: 2026/09/12 05:35:30 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return (0);
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	return (1);
}

void	sa(t_stack *stack_a)
{
	if (swap(stack_a))
	{
		stack_a->bench->sa++;
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack *stack_b)
{
	if (swap(stack_b))
	{
		stack_b->bench->sb++;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	stack_a->bench->ss++;
	ft_putstr_fd("ss\n", 1);
}
