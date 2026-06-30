/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:42:15 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/29 14:39:46 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		word;
	char	c;

	i = 0;
	if (argc != 2)
	{
		write(1,"\n", 1);
		return (0);
	}
	word = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '_')
		{
			if (argv[1][i] == '_')
				word = 1;
			i++;
		}
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '_')
		{
			c = argv[1][i];
			if (word == 0 && c >='A' && c <= 'Z')
				c = c + 32;
			else if (word == 1 && c >= 'a' && c <= 'z')
				c = c - 32;
			write(1, &c, 1);
			word = 0;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
// Assignment name  : snake_to_camel
// Expected files   : snake_to_camel.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in snake_case format
// and converts it into a string in lowerCamelCase format.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// Examples:
// $>./snake_to_camel "here_is_a_snake_case_word"
// hereIsASnakeCaseWord
// $>./snake_to_camel "hello_world" | cat -e
// helloWorld$
// $>./snake_to_camel | cat -e
// $
