/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 00:34:47 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/03 01:30:27 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

static char	to_lower(char c)
{
	char	res;

	if (is_upper(c))
		res = c + 32;
	else
		res = c;
	return (res);
}

static char	to_upper(char c)
{
	char	res;

	if (is_lower(c))
		res = c - 32;
	else
		res = c;
	return (res);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		start;
	char	c;

	i = 1;
	j = 0;
	start = 1;
	while(i < argc)
	{
		j = 0;
		start = 1;
		while(argv[i][j])
		{
			c = argv[i][j];
			if (c == ' ' || c == '\t')
					start = 1;
			else if (start == 1)
			{
				c = to_upper(c);
				start = 0;
			}
			else
				c = to_lower(c);
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
// Assignment name  : str_capitalizer
// Expected files   : str_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes one or several strings and, for each argument,
// capitalizes the first character of each word (If it's a letter, obviously),
// puts the rest in lowercase, and displays the result on the standard output,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string. If a word only has one letter, it must be
// capitalized.

// If there are no arguments, the progam must display \n.

// Example:

// $> ./str_capitalizer | cat -e
// $
// $> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
// A First Little Test$
// $> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
// __second Test A Little Bit   Moar Complex$
//    But... This Is Not That Complex$
//      Okay, This Is The Last 1239809147801 But Not    The Least    T$
// $>