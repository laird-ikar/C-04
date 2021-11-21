/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:17:01 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/21 14:18:40 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb <= -10)
			ft_putnbr(nb / -10);
		ft_putchar((-1 * (nb % 10)) + '0');
	}
	else if (nb >= 10)
		ft_putnbr(nb / 10);
	if (nb >= 0)
		ft_putchar(nb % 10 + '0');
}

void	fr_putchar(char c)
{
	write(1, &c, 1);
}
