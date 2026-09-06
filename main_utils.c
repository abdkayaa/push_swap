/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:01:53 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/05 16:26:18 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int stack_size(int argc, char **argv, t_options *opt)
{
    int size;
    int i;

    size=0;
    i=1;
    while(i<argc)
    {
        if(!parse_flag(argv[i],opt))
            size++;
        i++;
    }
    return(size);
}

static void check_and_store(char *arg, int *stack_a , int j)
{
    long tmp;

    if (!is_valid_number(arg))
    {
        free(stack_a);
        error_exit();
    }
    tmp = ft_atoi(arg);
    if (tmp < INT_MIN || tmp > INT_MAX)
    {
        free(stack_a);
        error_exit();
    }
    stack_a[j] = (int)tmp;
}


void fill_stack(int argc,char **argv,t_options *opt, int *stack_a)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        if (!parse_flag(argv[i], opt))
        {
            check_and_store(argv[i], stack_a, j);
            j++;
        }
        i++;
    }
}