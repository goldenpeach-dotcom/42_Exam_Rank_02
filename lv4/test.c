/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:43:32 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/07 02:32:54 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int num)
{
	long	n;
	int		digit;
	char	*res;

	digit = 1;
	n = num;
	if (n < 0)
	{
		digit += 1;
		n = -n;
	}
	while(n >= 10)
	{
		digit += 1;
		n = n / 10;
	}
	res = malloc(digit + 1);
	if (!res)
		return (NULL);
	res[digit] = '\0';
	n = num;
	if (n == 0)
		res[0] == '\0';
	while(n > 0)
	{
		res[--digit] = (n % 10) + '0';
		n = n / 10;
	}
	return(res);
}

int main(void)
{
	int test;
	int i;

	i = 0;
	test = 123456;
	printf("%s\n", ft_itoa(test));	
	return (0);
}