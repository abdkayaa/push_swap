/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 07:02:02 by abdkaya           #+#    #+#             */
/*   Updated: 2026/09/14 16:48:50 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

double	calculate_disorder(t_stack *a)
{
	int		i;
	int		j;
	double	total;
	double	mistakes;

	mistakes = 0;
	total = 0;
	i = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			total++;
			if (a->array[i] > a->array[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total == 0)
		return (0);
	return (mistakes / total);
}

static int	pick_mode(t_options *opt, t_stack *a)
{
	double	disorder;

	if (opt->simple)
		return (0);
	if (opt->medium)
		return (1);
	if (opt->complex)
		return (2);
	if (a->size <= 5)
		return (0);
	disorder = calculate_disorder(a);
	if (disorder < 0.2)
		return (0);
	if (disorder < 0.5)
		return (1);
	return (2);
}

void	apply_strategy(t_options *opt, t_stack *a, t_stack *b)
{
	int	mode;

	if (is_sorted(a->array, a->size))
		return ;
	mode = pick_mode(opt, a);
	a->bench->mode = mode;
	a->bench->adaptive = !opt->simple && !opt->medium && !opt->complex;
	if (mode == 0)
		sort_simple(a, b);
	else if (mode == 1)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
