/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 20:25:50 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/01 20:37:22 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if(!s)
		return (0);
	while(s[i] = '\0')
	{
		while (accept)
		if(s[i] == accept[j])
		{
			len++;
			i++;
			j++;
		}
		
	}
}
// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);