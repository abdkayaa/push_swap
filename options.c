/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:20:14 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/05 04:07:08 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;
    i=0;
    while( s1[i]&&s2[i]&&s1[i]==s2[i])
        i++;
    return((unsigned char)s1[i]-(unsigned char)s2[i]);
}

void init_options(t_options *opts)
{
    opts->simple=0;
    opts->medium=0;
    opts->complex=0;
    opts->adaptive=0;
    opts->bench=0;
}



int parse_flag(char *arg, t_options *opts)
{
    if(!ft_strcmp(arg,"--simple"))
        opts->simple = 1;
    else if (!ft_strcmp(arg,"--medium"))
        opts->medium = 1;
    else if (!ft_strcmp(arg,"--complex"))
        opts->complex = 1;
    else if (!ft_strcmp(arg,"--adaptive"))
        opts->adaptive = 1;
    else if (!ft_strcmp(arg,"--bench"))
        opts->bench = 1;
    else
        return(0);
    return(1);

}
void verify_strategies(t_options *opts)
{
    int count;

    count = opts->simple+opts->medium+opts->complex+opts->adaptive;
    if(count==0)
        opts->adaptive=1;
    return ;
}
