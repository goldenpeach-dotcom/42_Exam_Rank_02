/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:09:31 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/30 19:33:58 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_atoi(char *c)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while(c[i] == ' ' || c[i] == '\t' || (c[i] >= 9 && c[i] <= 13))
		i++;

	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
		{
			sign = -1;
			i++;
		}
	}
	while(c[i] != '\0' && c[i] >= '0' && c[i] <= '9')
	{
		num = num * 10 + (c[i] - '0');
		i++; 
	}
	return(num * sign);
}

static void	ft_putnbr_hex(int x)
{
	char	base[16] = "0123456789abcdef";

	if (x >= 16)
	{
		ft_putnbr_hex(x / 16);
	}
	write(1, &base[x % 16], 1);
}

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = ft_atoi(argv[1]);
	if (i < 0)
	{
		write(1, "-", 1);
		ft_putnbr_hex((unsigned int)-i);
	}
	else
	{
		ft_putnbr_hex((unsigned int)i);
	}
	write (1, "\n", 1);
	return (0);
}