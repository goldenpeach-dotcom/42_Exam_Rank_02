/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:40:25 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/29 15:41:06 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_list_size(t_list *begin_list)
{
	size_t	i;

	i = 0;
	while(!begin_list)
	{
		i++;
		begin_list = begin_list->next
	}
	return (i);

}
// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure, and turn it in as a file called
// ft_list.h:

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;
