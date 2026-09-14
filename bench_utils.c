/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 05:16:02 by abdkaya           #+#    #+#             */
/*   Updated: 2026/09/14 16:48:47 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_disorder(double disorder)
{
	int	value;
	int	integer_part;
	int	decimal_part;

	value = (int)(disorder * 10000 + 0.5);
	integer_part = value / 100;
	decimal_part = value % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(integer_part, 2);
	ft_putstr_fd(".", 2);
	if (decimal_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_strategy(t_bench *bench)
{
	if (bench->adaptive)
		ft_putstr_fd("[bench] strategy: Adaptive\n", 2);
	else if (bench->mode == 0)
		ft_putstr_fd("[bench] strategy: Simple\n", 2);
	else if (bench->mode == 1)
		ft_putstr_fd("[bench] strategy: Medium\n", 2);
	else
		ft_putstr_fd("[bench] strategy: Complex\n", 2);
	if (bench->mode == 0)
		ft_putstr_fd("[bench] complexity: O(n^2)\n", 2);
	else if (bench->mode == 1)
		ft_putstr_fd("[bench] complexity: O(n sqrt n)\n", 2);
	else
		ft_putstr_fd("[bench] complexity: O(n log n)\n", 2);
}
