/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:00:07 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/06 22:21:06 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1 ;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

static void	ft_putnbr_hex(int num)
{
	char	base[16] = "0123456789abcdef";

	if (num >= 16)
	{
		ft_putnbr_hex(num / 16);
	}
	write(1, &base[num % 16], 1);
}

int	main(int argc, char **argv)
{
	int	num;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	num = ft_atoi(argv[1]);
	if (!num)
		return (-1);
	ft_putnbr_hex((unsigned int)num);
	write(1, "\n", 1);
	return (0);
}
