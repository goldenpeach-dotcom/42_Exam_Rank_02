/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:39:36 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/02 19:54:57 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
static void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write (1, &bit, 1);
		i--;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	char bit;
	
	i = 0;
	bit = 0;
	while(i < 8)
	{
		bit = (bit << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (bit);
}

int main(void)
{
	unsigned char res;
	res = reverse_bits(8);

	print_bits(8);
	write(1, "\n", 1);
	print_bits(res);
	return (0);
}

// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0010  0110
// 	 ||
// 	 \/
//  0110  0100