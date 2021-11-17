/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:03:49 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/16 15:34:28 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add_char(int *i, char c);
int		ft_atoi(char *str);
void	is_space(char *str, int *i);

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	is_space(str, &i);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		add_char(&value, str[i]);
		i++;
	}
	return (sign * value);
}

void	is_space(char *str, int *i)
{
	char	c;

	c = str[0];
	while (c == ' '
		|| c == '\n'
		|| c == '\f'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
	{
		(*i)++;
		c = str[*i];
	}
}

void	add_char(int *i, char c)
{
	*i *= 10;
	*i += c - '0';
}
