/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:12:11 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/05 04:07:07 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return ;
    while (*s)
    {
        write(fd,s,1);
        s++;
    }
}

void error_exit(void)
{
    ft_putstr_fd("Error\n",2);
    exit(1);
}

int is_valid_number(char *str)
{
    int i;
    i=0;
    if(str[i]=='-'||str[i]=='+')    
        i++;
    if(str[i]=='\0')
        return (0);
    while(str[i])
    {
        if(str[i]<'0'||str[i]>'9')
            return(0);
        i++;
    }
    return(1);
}
long ft_atoi(char *num)
{
    long res;
    int sign;
    int i;

    res = 0;
    sign = 1;
    i = 0;
    while (num[i] == ' '|| (num[i]>=9 && num[i]<=13))
        i++;
    if (num[i]=='+'||num[i]=='-')
    {
        if(num[i]=='-')
            sign = -1;
        i++;
    }
    while(num[i]>='0'&&num[i]<='9')
    {
        res=(res * 10) + num[i] - '0';
        i++;
    }
    return(res * sign);
}


void ft_check_duplicates(int *stack, int size)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (stack[i] == stack[j])
                error_exit();
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    t_options opt;
    int *stack_a;
    int size;
    int i;
    int j;
    long tmp;

    if(argc<2)
        return(0);
    
    init_options(&opt);

    size=0;
    i=1;
    while(i<argc)
    {
        if(!parse_flag(argv[i],&opt))
            size++;
        i++;
    }

    if(size==0)
        return(0);
    stack_a = malloc(sizeof(int)*size);
    if(!stack_a)
        return(1);
    i=1;
    j=0;

    while(i<argc)
    {
        if(!parse_flag(argv[i],&opt))
        {
            if(!is_valid_number(argv[i]))
            {
                free(stack_a);
                error_exit();
            }
            tmp=ft_atoi(argv[i]);
            if(tmp<INT_MIN||tmp>INT_MAX)
            {
                free(stack_a);
                error_exit();
            }
            stack_a[j]=(int)tmp;
            j++;
        }
        i++;
    }

    verify_strategies(&opt);
    ft_check_duplicates(stack_a, size);

    free(stack_a);
    return(0);
}