/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:01:53 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/14 17:02:45 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	count_and_free(char **strs)
{
	int	j;

	j = 0;
	while (strs[j])
	{
		free(strs[j]);
		j++;
	}
	free(strs);
	return (j);
}

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	stack_size(int argc, char **argv, t_options *opt)
{
	int		i;
	int		count;
	char	**strs;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (parse_flag(argv[i], opt))
		{
			i++;
			continue ;
		}
		strs = ft_split(argv[i], ' ');
		if (!strs || !strs[0])
		{
			free(strs);
			error_exit();
		}
		count += count_and_free(strs);
		i++;
	}
	return (count);
}

static int	check_and_store(char *arg, int *stack_a, int j)
{
	char	**split;
	int		k;
	long	tmp;

	split = ft_split(arg, ' ');
	if (!split)
		error_exit();
	k = 0;
	while (split[k])
	{
		tmp = ft_atol(split[k]);
		if (!is_valid_number(split[k]) || tmp < INT_MIN || tmp > INT_MAX)
		{
			free(stack_a);
			ft_free_split(split);
			error_exit();
		}
		stack_a[j++] = (int)tmp;
		k++;
	}
	ft_free_split(split);
	return (j);
}

void	fill_stack(int argc, char **argv, t_options *opt, int *stack_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!parse_flag(argv[i], opt))
			j = check_and_store(argv[i], stack_a, j);
		i++;
	}
}
