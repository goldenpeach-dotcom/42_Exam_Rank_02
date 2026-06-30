/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:40:02 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/15 15:00:41 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	tmp;

	i = 0;
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		tmp = argv[1][i];
		if ('a' <= tmp && tmp <= 'z')
		{
			tmp = tmp - ('a' - 'A');
			write(1, &tmp, 1);
		}
		else if ('A' <= tmp && tmp <= 'Z')
		{
			tmp = tmp + ('a' - 'A');
			write(1, &tmp, 1);
		}
		else
		{
			write(1, &tmp, 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
