/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:26:35 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/05 16:30:35 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_options
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_options;

typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

void	sa(t_stack *stack_a);

int		stack_size(int argc, char **argv, t_options *opt);
void	fill_stack(int argc, char **argv, t_options *opt, int *stack_a);

void	ft_putstr_fd(char *s, int fd);
void	error_exit(void);
long	ft_atoi(char *num);
void	ft_check_duplicates(int *stack, int size);

int		is_valid_number(char *str);

void	init_options(t_options *opts);
int		ft_strcmp(char *s1, char *s2);
int		parse_flag(char *arg, t_options *opts);
void	verify_strategies(t_options *opts);

#endif