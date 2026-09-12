/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   put_fd.c                                             :+:      :+:    :+: */
/*                                                      +#+ +#+         +#+   */
/*   By: abdkaya <abdkaya@student.42istanbul.com.tr>  +#+  +#+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/09/10 20:19:59 by abdkaya             #+#    #+#           */
/*   Updated: 2026/09/12 05:35:30 by abdkaya            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	long	number;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr_fd((int)(number / 10), fd);
	digit = (number % 10) + '0';
	write(fd, &digit, 1);
}
