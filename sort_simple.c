/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   sort_simple.c                                        :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/08 14:22:46 by abdkaya             #+#    #+#           */
/*   Updated: 2026/09/14 13:34:48 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


int min_index(t_stack *a)
{
    int min;
    int i;

    min = 0;
    i = 1;
    while (i < a->size)
    {
        if (a->array[min] > a->array[i])
            min = i;
        i++;
    }
    return (min);
}

void	three_sort(t_stack *a)
{
	if (a->size == 2 && a->array[0] > a->array[1])
		sa(a);
	if (a->size < 3)
		return ;
	if (min_index(a) == 0 && a->array[1] > a->array[2])
	{
		rra(a);
		sa(a);
	}
	else if (min_index(a) == 1)
	{
		if (a->array[0] < a->array[2])
			sa(a);
		else
			ra(a);
	}
	else if (min_index(a) == 2)
	{
		if (a->array[0] > a->array[1])
			sa(a);
		rra(a);
	}
}

void    move_top(t_stack *a, int index)
{
    if(index < (a->size/2))
    {
        while (index > 0)
        {
            ra(a);
            index--;
        }
    }
    else
    {
        while(a->size -index)
        {
            rra(a);
            index++;
        }
    }
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int	index;

	while (a->size > 3)
	{
		index = min_index(a);
		move_top(a, index);
		pb(a, b);
	}
	three_sort(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_simple(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		three_sort(a);
		return ;
	}
	selection_sort(a, b);
}
