/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:04:14 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/30 21:20:49 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		digit;

	digit = 1;
	num = n;

	if (num < 0)
	{
		num = -num;
		digit = digit + 1;
	}
	while(num >= 10)
	{
		digit = digit + 1;
		num = num / 10;
	}
	str = malloc(digit + 1);
	if (!str)
		return (NULL);
	num = n;
	str[digit] = '\0';
	if(num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (n == 0)
	str[0] = '\0';
	while(num > 0)
	{
		str[--digit] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

int main(void)
{
	printf("%s\n", ft_itoa(15689));
	return (0);
}