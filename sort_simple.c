/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   sort_simple.c                                        :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/08 14:22:46 by abdkaya             #+#    #+#           */
/*   Updated: 2026/09/12 16:18:40 by abdkaya            ###   ########.fr     */
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
void    three_sort(t_stack *a)
{
    int index;

    index = min_index(a);
    if (a->size == 2 && a->array[1] > a->array[0])
    {
        if(a->array[0] > a->array[1])
        {
			sa(a);
			rra(a);
		}
        else
            rra(a);
    }
}
// 6 8 5
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
// minimum index buluyo 3 e kadar düşünce duruyor

void    selection_sort(t_stack *a, t_stack *b)
{
    int index;

    while(a->size > 3)
    {
        index = min_index(a);
        move_top(a, index);
        pb(a, b);
    }
    three_sort(a);
    while (a->size > 0)
        pa(a, b);

}
#include <stdio.h>
int main()
{
    t_stack a;
    int ar[]= {2,3,1,7,4,8,5};
    a.array = ar;
    a.size = 7;
    printf("%d",min_index(&a));

}