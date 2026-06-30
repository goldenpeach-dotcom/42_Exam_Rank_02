/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:37:14 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/29 23:43:58 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr(long n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	(void)argv;
	i = argc - 1;
	ft_putnbr(i);
	write(1, "\n", 1);
	return (0);
}

// void	putnbr(int n)
// {
//     char    buf[12];
//     int     i;

//     i = 11;
//     buf[i] = '\0';
//     if (n == 0)
//     {
//         write(1, "0", 1);
//         return ;
//     }
//     while (n > 0)
//     {
//         i--;
//         buf[i] = (n % 10) + '0';
//         n = n / 10;
//     }
//     write(1, &buf[i], 11 - i);
// }
// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays the number of arguments passed to it, followed by
// a newline.

// If there are no arguments, just display a 0 followed by a newline.

// Example:

// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>