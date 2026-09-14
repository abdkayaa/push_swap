/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 00:09:41 by abdkaya           #+#    #+#             */
/*   Updated: 2026/09/14 16:48:59 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	*make_copy(t_stack *a)
{
	int	*tmp;
	int	i;

	tmp = malloc(a->size * sizeof(int));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < a->size)
	{
		tmp[i] = a->array[i];
		i++;
	}
	return (tmp);
}

static void	assign_ranks(t_stack *a, int *tmp)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < a->size)
	{
		count = 0;
		j = 0;
		while (j < a->size)
		{
			if (tmp[j] < tmp[i])
				count++;
			j++;
		}
		a->array[i] = count;
		i++;
	}
}

void	index_compress(t_stack *a)
{
	int	*tmp;

	tmp = make_copy(a);
	if (!tmp)
		return ;
	assign_ranks(a, tmp);
	free(tmp);
}

void	rotate_to_top(t_stack *s, int idx, int is_b)
{
	int	steps;
	int	i;

	if (idx <= s->size / 2)
		steps = idx;
	else
		steps = s->size - idx;
	i = 0;
	while (i < steps)
	{
		if (idx <= s->size / 2 && !is_b)
			ra(s);
		else if (idx <= s->size / 2)
			rb(s);
		else if (!is_b)
			rra(s);
		else
			rrb(s);
		i++;
	}
}

int	find_nearest(t_stack *s, int chunk, int k)
{
	int	i;
	int	best;
	int	best_cost;
	int	cost;

	i = 0;
	best = -1;
	best_cost = s->size + 1;
	while (i < s->size)
	{
		if (s->array[i] / k == chunk)
		{
			cost = i;
			if (s->size - i < cost)
				cost = s->size - i;
			if (cost < best_cost)
			{
				best_cost = cost;
				best = i;
			}
		}
		i++;
	}
	return (best);
}
