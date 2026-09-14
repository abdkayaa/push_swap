/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:23:49 by abdkaya           #+#    #+#             */
/*   Updated: 2026/09/14 16:49:17 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	re_index(t_stack *a)
{
	int	*temp;
	int	i;
	int	j;

	temp = malloc(sizeof(int) * a->size);
	if (!temp)
		error_exit();
	i = -1;
	while (++i < a->size)
		temp[i] = a->array[i];
	sort_array(temp, a->size);
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
		{
			if (a->array[i] == temp[j])
				break ;
		}
		a->array[i] = j;
	}
	free(temp);
}

static void	execute_radix_pass(t_stack *a, t_stack *b, int bit, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((a->array[0] >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	max_val;
	int	i;

	if (is_sorted(a->array, a->size))
		return ;
	re_index(a);
	max_val = a->size - 1;
	max_bits = 0;
	while ((max_val >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		execute_radix_pass(a, b, i, a->size);
		i++;
	}
}
