/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:43:32 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/10 01:10:15 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;
	int				swapped;

	i = 0;
	tmp = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while(i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}	
	}
	
}

int main(void)
{
	int v[] = {5,3,1,6,9,2};
	int i;

	i = 0;
	sort_int_tab(v, 6);
	while(i < 6)
	{
		printf("%d\n", v[i]);
		i++;
	}
	return (0);
}
// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.