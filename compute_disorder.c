/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 07:02:02 by abdkaya           #+#    #+#             */
/*   Updated: 2026/09/05 16:13:31 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(int *stack_a, int size)
{
	int	i;

	if (size <= 1)
		return (1);
	i = 0;
	while (i < size - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

double	compute_disorder(int *stack_a, int size)
{
	long long	mistakes;
	long long	total_pairs;
	int			i;
	int			j;

	if (size <= 1)
		return (0, 0);
	mistakes = 0;
	total_pairs = ((long long)size * (size - 1)) / 2;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a[i] > stack_a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}
