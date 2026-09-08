/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:26:35 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/08 09:59:02 by okaymazo         ###   ########.fr       */
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

double	calculate_disorder(t_stack *a);
int		is_sorted(int *array, int size);

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

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

#endif