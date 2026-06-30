/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:26:07 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/29 16:44:58 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	long	len;
	long	i;
	int	*res;

	i = 0;
	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);

	while(i < len)
	{
		if (start < end)
			res[i] = (long)start + i;
		else
			res[i] = (long)start - i;
		i++;
	}
	return (res);
}

int	main(void)
{
	int	*nums;
	int	i;
	int len;

	i = 0;
	nums = ft_range(0, -3);
	len = 4;
	if (!nums)
		return (1);
	while (i < len)
	{
		printf("%d\n", nums[i]);
		i++;
	}
	free(nums);
	return (0);
}
// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);
// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.