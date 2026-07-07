/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:00:39 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/07 00:36:41 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_atoi_mult(const char *s)
{
	int num;
	int	i;

	i = 0;
	num = 0;
	while(s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num);
}

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	write(1, str, i);
}

static void ft_putnbr(int n)
{
	int num;

	num = n;
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

int	main(int argc, char **argv)
{
	int	i;
	int	mult;
	int answer;

	i = 1;
	mult = 0;
	answer = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putstr(argv[1]);
		write(1, " = ", 3);
		mult = ft_atoi_mult(argv[1]);
		answer = i * mult;
		ft_putnbr(answer);
		write(1, "\n", 1);
		i++;
	}
	return (0);	
}
// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>