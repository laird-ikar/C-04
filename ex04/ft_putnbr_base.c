/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:21:36 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/22 07:08:48 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		is_valid(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	base_size = is_valid(base);
	if (base_size)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			if (nbr <= -base_size)
				ft_putnbr_base(nbr / base_size * -1, base);
			write(1, &base[-(nbr % base_size)], 1);
		}
		else if (nbr >= base_size)
			ft_putnbr_base(nbr / base_size, base);
		if (nbr >= 0)
			write(1, &base[nbr % base_size], 1);
	}
}

int	is_valid(char *base)
{
	int	size;
	int	j;

	j = 0;
	size = 0;
	while (base[size])
	{
		if (base[size] == '+'
			|| base[size] == '-')
			return (0);
		j = 0;
		while (j < size)
		{
			if (base[size] == base [j])
				return (0);
			j++;
		}
		size++;
	}
	if (size >= 2)
		return (size);
	else
		return (0);
}
