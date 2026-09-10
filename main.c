/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   main.c                                               :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/07 17:51:05 by okaymazo            #+#    #+#           */
/*   Updated: 2026/09/10 17:55:21 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	init_stacks(int argc, char **argv, t_options *opt, t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(argc, argv, opt);
	if (size == 0)
		exit(0);
	a->array = malloc(sizeof(int) * size);
	b->array = malloc(sizeof(int) * size);
	if (!a->array || !b->array)
	{
		free(a->array);
		free(b->array);
		error_exit();
	}
	a->size = size;
	b->size = 0;
	fill_stack(argc, argv, opt, a->array);
	verify_strategies(opt);
	ft_check_duplicates(a->array, a->size);
}


int	main(int argc, char **argv)
{
	t_options	opt;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc < 2)
		return (0);
	init_options(&opt);
	init_stacks(argc, argv, &opt, &stack_a, &stack_b);
	apply_strategy(&opt, &stack_a, &stack_b);
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}
