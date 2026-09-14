/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   sort_medium.c                                        :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/08 14:23:17 by abdkaya             #+#    #+#           */
/*   Updated: 2026/09/14 13:44:39 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_max(t_stack *s, int chunk, int k)
{
	int	i;
	int	best;
	int	best_val;

	i = 0;
	best = -1;
	best_val = -1;
	while (i < s->size)
	{
		if (s->array[i] / k == chunk && s->array[i] > best_val)
		{
			best_val = s->array[i];
			best = i;
		}
		i++;
	}
	return (best);
}

static int	has_chunk(t_stack *b, int chunk, int k)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (b->array[i] / k == chunk)
			return (1);
		i++;
	}
	return (0);
}

static void	push_chunks(t_stack *a, t_stack *b, int k)
{
	int	chunk;
	int	n;
	int	remaining;
	int	idx;

	n = a->size;
	chunk = 0;
	while (chunk * k < n)
	{
		remaining = k;
		if (n - chunk * k < remaining)
			remaining = n - chunk * k;
		while (remaining > 0)
		{
			idx = find_nearest(a, chunk, k);
			rotate_to_top(a, idx, 0);
			pb(a, b);
			remaining--;
		}
		chunk++;
	}
}

static void	push_back(t_stack *a, t_stack *b, int k)
{
	int	chunk;
	int	idx;

	chunk = (b->size - 1) / k;
	while (b->size > 0)
	{
		idx = find_max(b, chunk, k);
		rotate_to_top(b, idx, 1);
		pa(a, b);
		if (!has_chunk(b, chunk, k))
			chunk--;
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	k;

	if (a->size <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	k = 1;
	while (k * k <= a->size)
		k++;
	k--;
	index_compress(a);
	push_chunks(a, b, k);
	push_back(a, b, k);
}