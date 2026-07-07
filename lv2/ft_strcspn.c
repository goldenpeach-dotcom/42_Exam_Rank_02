/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:02:44 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/02 13:57:39 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
 #include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s || !reject)
		return (0);
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	printf("%lu\n", ft_strcspn("12345abcde", "abc"));
// 	return (0);
// }