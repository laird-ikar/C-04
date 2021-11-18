/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:01:35 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/18 13:36:56 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base);
int		is_valid(char *base);
int		value_from_base(int i, char *base);
int		is_in_base(char c, char *base);
void	add_char(int *value, char c, char *base);
void	sign_gestion(char *str, int *i, int *sign);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_size;
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	base_size = is_valid(base);
	if (base_size)
	{
		i = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
		sign_gestion(str, &i, &sign);
		while (is_in_base(str[i], base))
		{
			add_char(&value, str[i], base);
			i++;
		}
	}
	return (sign * value);
}

void	add_char(int *value, char c, char *base)
{
	int	i;
	int	base_size;

	i = 0;
	base_size = is_valid(base);
	while (base[i] != c)
		i++;
	*value *= base_size;
	*value += i;
}

int	is_valid(char *base)
{
	int	size;
	int	j;

	j = 0;
	size = 0;
	while (base[size])
	{
		if (base[size] == '+' || base[size] == '-'
			|| base[size] == ' ' || base[size] == '\n' || base[size] == '\f'
			|| base[size] == '\r' || base[size] == '\t' || base[size] == '\v')
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

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	sign_gestion(char *str, int *i, int *sign)
{
	while (str[*i] == '+'
		|| str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}
