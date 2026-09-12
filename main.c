/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   main.c                                               :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/07 17:51:05 by okaymazo            #+#    #+#           */
/*   Updated: 2026/09/12 05:43:06 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	init_stacks(int argc, char **argv, t_options *opt,
		t_stack stacks[2])
{
	int		size;
	t_stack	*a;
	t_stack	*b;

	size = stack_size(argc, argv, opt);
	if (size == 0)
		exit(0);
	a = &stacks[0];
	b = &stacks[1];
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
	t_stack		stacks[2];
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_bench		bench;

	if (argc < 2)
		return (0);
	stack_a = &stacks[0];
	stack_b = &stacks[1];
	init_options(&opt);
	init_bench(&bench);
	init_stacks(argc, argv, &opt, stacks);
	stack_a->bench = &bench;
	stack_b->bench = &bench;
	bench.disorder = calculate_disorder(stack_a);
	apply_strategy(&opt, stack_a, stack_b);
	if (opt.bench)
		print_benchmark(&bench);
	free(stack_a->array);
	free(stack_b->array);
	return (0);
}
