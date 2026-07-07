/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 20:25:50 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/02 14:07:36 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	if (!s || !accept)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				break ;
			j++;
		}
		if (accept[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

int main(void)
{
	printf("%lu\n", ft_strspn("12345a678", "0123456789"));
	return (0);
}


// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);

// The  strspn() function calculates the length (in bytes) of the initial segment of s which consists en‐
//        tirely of bytes in accept.

//        The strcspn() function calculates the length of the initial segment of s which  consists  entirely  of
//        bytes not in reject.
// RETURN VALUE
//        The  strspn()  function  returns the number of bytes in the initial segment of s which consist only of
//        bytes from accept.

//        The strcspn() function returns the number of bytes in the initial segment of s which are  not  in  the
//        string reject.