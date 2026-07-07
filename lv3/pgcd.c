/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:58:39 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/02 20:11:15 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


unsigned int	hcf(unsigned int a, unsigned int b)
{
	unsigned long	mod;
	unsigned long	big;
	unsigned long	small;

	mod = 0;
	big = 0;
	small = 0;
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}
	while (small > 0)
	{
		mod = big % small;
		big = small;
		small = mod;
	}
	return (big);
}

int main(int argc, char **argv)
{
	unsigned int	i;
	unsigned int	j;
	
	i = 0;
	j = 0;
	if (argc == 3)
	{
		i = atoi(argv[1]);
		j = atoi(argv[2]);	
		printf("%d", hcf(i ,j));
	}
	printf("\n");
	return (0);
}
// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e
// 1$
// $> ./pgcd | cat -e
// $