/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 01:31:07 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/05 01:33:43 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_foreach(t_list *begin_list, (*f)(void*))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
// Assignment name  : ft_list_foreach
// Expected files   : ft_list_foreach.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a list and a function pointer, and applies this
// function to each element of the list.

// It must be declared as follows:

// void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

// The function pointed to by f will be used as follows:

// (*f)(list_ptr->data);

// You must use the following structure, and turn it in as a file called
// ft_list.h:

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;