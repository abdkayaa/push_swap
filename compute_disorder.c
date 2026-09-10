/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   compute_disorder.c                                   :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/08/31 07:02:02 by abdkaya             #+#    #+#           */
/*   Updated: 2026/09/10 17:39:43 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

double	calculate_disorder(t_stack *a)
{
	int		i;
	int		j;
	double	total;
	double	mistakes;

	mistakes = 0;
	total = 0;
	i = 0;
	while (i < a->size - 1)//total diziden kaç tanesinin sırası bozuk oranını hesaplar
	{
		j = i + 1;
		while (j < a->size) //önceden size-1 di öyleyken son elemanla hiç karşılaştırma yapılmıyor
							//hesaplamanın doğru olması için her türlü son elemanla olan bozulmaya da bakılmalı
		{
			total++;
			if (a->array[i] > a->array[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total == 0)
		return (0);
	return (mistakes / total);
}

void	apply_strategy(t_options *opt, t_stack *a, t_stack *b)
{
	double	disorder;

	if (is_sorted(a->array, a->size)) //sıralıysa çık
		return ;
	if (opt->simple)//flag verilmişse buradan algoritmalara stack gönderiliyor
					//veya s_optionstaki adaptive flag olarka gönderirlirse yani bozulma oranına
					//göre hesapla denirse diğerleri 0 kalıyor ve aşağıya kayıyor 
		sort_simple(a, b);
	else if (opt->medium)
		sort_medium(a, b);
	else if (opt->complex)
		sort_complex(a, b);
	else //flag verilmemişse aşağıda calculate disorder ile bozulma
		// oranına bağlı algoritmalara gönderiyoruz stackleri
	{
		disorder = calculate_disorder(a);
		if (disorder < 0.2)
			sort_simple(a, b);
		else if (disorder < 0.5)
			sort_medium(a, b);
		else
			sort_complex(a, b);
	}
}
