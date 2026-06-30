/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:38:08 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/26 15:32:16 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

static int	is_alpha(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z' ));
}

static int	is_upper(char c)
{
	return ('A' <= c && c <= 'Z' );
}

int	main(int argc, char	**argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while(argv[1][i] != '\0')
	{
		if(!is_alpha(argv[1][i]))
			write(1, &argv[1][i], 1);
		else
		{
			if(!is_upper(argv[1][i]))
			{
				k = 0;
				j = argv[1][i] - 'a' + 1;
				while(k < j)
				{
					write(1, &argv[1][i], 1);
					k++;
				}
			}
			else
			{
				k = 0;
				j = argv[1][i] - 'A' + 1;
				while (k < j)
				{
					write(1, &argv[1][i], 1);
					k++;
				}
			}
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>