/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:27:36 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/15 16:54:57 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while (argv[1][i])
	{
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		if (argv[1][i])
			write (1, "   ", 3);
	}
	write (1, "\n", 1);
	return (0);
}
