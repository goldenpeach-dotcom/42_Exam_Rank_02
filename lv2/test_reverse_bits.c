/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 16:32:36 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/05 22:58:53 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	size_t			i;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
}

void print_bits(unsigned char c)
{
	for (int i = 7; i >= 0; i--)
		printf("%d", (c >> i) & 1);
	printf("\n");
}

int	main(void)
{
	unsigned char	c;

	c = reverse_bits(2);
	print_bits(c);
	return (0);
}
