/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:52:52 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/15 14:37:41 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	unsigned int	num;

	num = n;
	if (num <= 0)
		return (0);
	while (num > 1)
	{
		if (num % 2 != 0)
			return (0);
		n = n / 2;
	}
	return (1);
}
