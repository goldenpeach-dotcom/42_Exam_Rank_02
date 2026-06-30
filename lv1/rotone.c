/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:34:14 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/27 02:33:40 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

static int is_alpha(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while(argv[1][i])
	{
		if (!is_alpha(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		else
		{
			// if(('a' <= argv[1][i] && argv[1][i]<= 'y') || ('A' <= argv[1][i] && argv[1][i] <= 'Y'))
			if ('z' == argv[1][i] || 'Z' == argv[1][i])
				c = argv[1][i] - 25;
			else
				c = argv[1][i] + 1;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
// Assignment name  : rotone
// Expected files   : rotone.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the next one in alphabetical order.

// 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

// The output will be followed by a \n.

// If the number of arguments is not 1, the program displays \n.

// Example:

// $>./rotone "abc"
// bcd
// $>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
// Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
// $>./rotone "AkjhZ zLKIJz , 23y " | cat -e
// BlkiA aMLJKa , 23z $
// $>./rotone | cat -e
// $
// $>
// $>./rotone "" | cat -e
// $
// $>