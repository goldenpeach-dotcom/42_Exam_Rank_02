/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:00:11 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/29 16:45:11 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	long	len;
	long	i;
	int		*nums;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	nums = malloc(sizeof(int) * len);
	if (!nums)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (start < end)
			nums[i] = (long)end - i;
		else
			nums[i] = (long)end + i;
		i++;
	}
	return(nums);
}

int	main(void)
{
	int	*nums;
	int	i;
	int len;

	i = 0;
	nums = ft_rrange(0, -3);
	len = 3;
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

// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.