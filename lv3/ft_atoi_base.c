/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:34:43 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/07 14:18:23 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	long 	num;
	int		sign;
	int		digit;

	sign = 1;
	num = 0;
	if (!str || str_base < 2 || str_base > 16)
	{
		return (0);
	}
	while (*str == ' ' || *str == '\t' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	digit = value(*str);
	while(digit >= 0 && digit < str_base)
	{
		num = num * str_base + digit;
		str++;
		digit = value(*str);
	}
	return ((int)(num * sign));
}

int main(void)
{
	printf("%d\n", ft_atoi_base("19", 8));
	printf("%d\n", ft_atoi_base("18", 8));
	printf("%d\n", ft_atoi_base("17", 8));
	printf("%d\n", ft_atoi_base("ff", 16));
	printf("%d\n", ft_atoi_base("FF", 16));
	printf("%d\n", ft_atoi_base("-10", 2));
	printf("%d\n", ft_atoi_base("  42", 10));
	return (0);
}
// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);