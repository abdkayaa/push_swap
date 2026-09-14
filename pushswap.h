/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:26:35 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/14 17:01:52 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disorder;
	int		mode;
	int		adaptive;
}	t_bench;
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
	int		*array;
	int		size;
	t_bench	*bench;
}	t_stack;

void	init_bench(t_bench *bench);
int		bench_total(t_bench *bench);
void	print_benchmark(t_bench *bench);
void	print_strategy(t_bench *bench);
void	print_disorder(double disorder);

int		is_sorted(int *array, int size);
double	calculate_disorder(t_stack *a);
void	apply_strategy(t_options *opt, t_stack *a, t_stack *b);

char	**ft_split(char const *s, char c);
int		stack_size(int argc, char **argv, t_options *opt);
void	fill_stack(int argc, char **argv, t_options *opt, int *stack_a);

int		ft_strcmp(char *s1, char *s2);
void	init_options(t_options *opts);
int		parse_flag(char *arg, t_options *opts);
void	verify_strategies(t_options *opts);

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	error_exit(void);
int		is_valid_number(char *str);
long	ft_atol(char *num);
void	ft_check_duplicates(int *stack, int size);
int		is_empty_str(char *str);

void	sort_simple(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);

void	index_compress(t_stack *a);
void	rotate_to_top(t_stack *s, int idx, int is_b);
int		find_nearest(t_stack *s, int chunk, int k);

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