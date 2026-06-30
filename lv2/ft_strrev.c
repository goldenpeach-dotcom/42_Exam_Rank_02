/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 12:03:10 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/27 12:29:01 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		i++;
	i--;
	while (i > j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i--;
		j++;
	}
	return(str);
}

int	main(void)
{
	char str[] = "abcdefg";
	int	i;

	i = 0;
	ft_strrev(str);
	while(str[i] != '\0')
	{
		printf("%c\n", str[i]);
		i++;
	}
	return (0);
}
// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// ---------------------------
// -----------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);