/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   rev_rotates.c                                        :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/08 08:27:13 by okaymazo            #+#    #+#           */
/*   Updated: 2026/09/13 19:15:17 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	rev_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return (0);
	tmp = stack->array[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = tmp;
	return (1);
}

void	rra(t_stack *stack_a)
{
	if (rev_rotate(stack_a))
	{
		stack_a->bench->rra++;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stack *stack_b)
{
	if (rev_rotate(stack_b))
	{
		stack_b->bench->rrb++;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	stack_a->bench->rrr++;
	ft_putstr_fd("rrr\n", 1);
}
