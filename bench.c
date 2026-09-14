/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   bench.c                                              :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/10 19:37:45 by abdkaya             #+#    #+#           */
/*   Updated: 2026/09/14 05:20:20 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->mode = 0;
	bench->adaptive = 0;
}

int	bench_total(t_bench *bench)
{
	return (bench->sa + bench->sb + bench->ss + bench->pa
		+ bench->pb + bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr);
}

static void	print_metric(char *label, int val)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(val, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_bench *bench)
{
	print_disorder(bench->disorder);
	print_strategy(bench);
	print_metric("[bench] operations: ", bench_total(bench));
	print_metric("[bench] sa: ", bench->sa);
	print_metric("[bench] sb: ", bench->sb);
	print_metric("[bench] ss: ", bench->ss);
	print_metric("[bench] pa: ", bench->pa);
	print_metric("[bench] pb: ", bench->pb);
	print_metric("[bench] ra: ", bench->ra);
	print_metric("[bench] rb: ", bench->rb);
	print_metric("[bench] rr: ", bench->rr);
	print_metric("[bench] rra: ", bench->rra);
	print_metric("[bench] rrb: ", bench->rrb);
	print_metric("[bench] rrr: ", bench->rrr);
}
