/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 12:56:25 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/27 16:05:08 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc,char **argv)
{
	int				i;
	int				j;
	char			seen[256] = {0};
	unsigned char	c;

	i = 0;
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	
	while(argv[1][i])
	{
		c = argv[1][i];
		if (seen[c] == 0)
		{
			write(1, &argv[1][i], 1);
			seen[c] = 1;
		}
		i++;
	}
	j = 0;
	while(argv[2][j])
	{
		c = argv[2][j];
		if(seen[c] == 0)
		{
			write(1, &argv[2][j], 1);
			seen[c] = 1;
		}
		j++;	
	}
	write(1, "\n", 1);
	return (0);
}
// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write()
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>