/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   bench.c                                              :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/10 19:37:45 by abdkaya             #+#    #+#           */
/*   Updated: 2026/09/10 20:27:59 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_bench(t_bench *bench)
{
	// Program her calistiginda eski sayac kalintilarini temizler.
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
}

int	bench_total(t_bench *bench)
{
	// Tum operation turlerini toplayarak toplam sayiyi verir.
    return (bench->sa + bench->sb + bench->ss
        + bench->pa + bench->pb + bench->ra
        + bench->rb + bench->rr + bench->rra
        + bench->rrb + bench->rrr);
}

static void	print_metric(char *label, int val)
{
	// Benchmark etiketini ve degerini stderr'e yazdirir.
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(val, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_bench *bench)
{
	// Bu fonksiyon yalnizca --bench verildiginde main tarafindan cagrilir.
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
