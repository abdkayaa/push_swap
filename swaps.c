/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:22:48 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/05 16:25:46 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void sa(t_stack *stack_a)
{
    int tmp;

    if(stack_a->size < 2)
        return;
    tmp=stack_a->array[0];
    stack_a->array[0]=stack_a->array[1];
    stack_a->array[1]=tmp;
    ft_putstr_fd("sa\n",1);
}