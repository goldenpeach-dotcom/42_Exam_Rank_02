/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 00:01:56 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/05 23:07:15 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	main(int argc, char **argv)
{
	int		i;
	int		first;
	char	c;

	i = 0;
	first = 1;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		if (!argv[1][i])
			break ;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '_')
		{
			c = argv[1][i];
			if (first == 1)
			{
				if (is_upper(c))
					c = argv[1][i] + 32;
				first = 0;
			}
			else
			{
				if (is_upper(c))
				{
					write(1, "_", 1);
					c = argv[1][i] + 32;
				}
				else
					c = argv[1][i];
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
// Assignment name  : camel_to_snake
// Expected files   : camel_to_snake.c
// Allowed functions: malloc, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in lowerCamelCase format
// and converts it into a string in snake_case format.

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// Examples:
// $>./camel_to_snake "hereIsACamelCaseWord"
// here_is_a_camel_case_word
// $>./camel_to_snake "helloWorld" | cat -e
// hello_world$
// $>./camel_to_snake | cat -e
// $