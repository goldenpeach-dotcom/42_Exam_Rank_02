/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 00:53:37 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/28 20:48:31 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n < 2)
		return(0);
	while(i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;		
	}
	return (1);
}

static int	ft_atoi_p(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return	(res);
}

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
	long sum;
	long tmp;

	sum = 0;
	if (argc != 2)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return (0);
	}
	tmp = ft_atoi_p(argv[1]);
	if (tmp < 2)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return (0);
	}
	i = 3;
	sum = 2;
	while (i <= tmp)
	{
		if (is_prime(i))
			sum = sum + i;
		i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>