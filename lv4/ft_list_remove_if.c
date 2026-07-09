/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:04:05 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/09 17:41:46 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)())
{
	t_list	*current;
	t_list	*tmp;
	
	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	current = *begin_list;
	while(current && current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			tmp = current->next;
			current->next = tmp->next;
			free(tmp);
		}
		else
			current = current->next;
	}
}

int cmp(void *a, void *b)
{
	return(*(int *)a - *(int *)b);
}
int main(void)
{
	int	v[] = {1,3,2,2,4,5};
	t_list	*lst;
	t_list	*n[5];
	int		i;
	int		target;

	i = 0;
	while(i < 5)
	{
		n[i] = malloc(sizeof(t_list));
		n[i]->data = &v[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		n[i]->next = n[i + 1];
		i++;
	}
	n[4]->next = NULL;
	lst = n[0];
	target = 2;
	ft_list_remove_if(&lst, &target,cmp)
	while (lst)
	{
		printf("%d\n", *(int *)lst->data)
		lst =  lst->next;
	}
	printf("\n");
	return (0);
}


// // Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.

// You have to use the ft_list.h file, which will contain:

// $>cat ft_list.h
// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;
// ↓長すぎるから使わないけど一応とっておく
// int my_strcmp(void *data, void *ref)
// {
//     return strcmp((char *)data, (char *)ref);
// }

// // リスト表示用ヘルパー関数
// void print_list(t_list *list)
// {
//     if (!list)
//     {
//         printf("(empty)\n");
//         return;
//     }
//     while (list)
//     {
//         printf("[%s] -> ", (char *)list->data);
//         list = list->next;
//     }
//     printf("NULL\n");
// }

// // 新しいノードを作成するヘルパー関数
// t_list *create_node(void *data)
// {
//     t_list *node = (t_list *)malloc(sizeof(t_list));
//     if (!node) return (NULL);
//     node->data = data;
//     node->next = NULL;
//     return (node);
// }

// int main(void)
// {
// // 1. 手動でリストを作成 (ベタ書き)
// // 初期状態: "delete" -> "keep1" -> "delete" -> "keep2" -> NULL
//     t_list *node1 = create_node("delete");
//     t_list *node2 = create_node("keep1");
//     t_list *node3 = create_node("delete");
//     t_list *node4 = create_node("keep2");

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node4;

//     t_list *head = node1;

// // 2. 削除前のリストを表示
//     printf("削除前: ");
//     print_list(head);
// // 3. 関数の実行 ("delete" という文字列を持つノードを削除)
//     char *target = "delete";
//     ft_list_remove_if(&head, target, my_strcmp);
// // 4. 削除後のリストを表示
//     printf("削除後: ");
//     print_list(head);
// // 5. 残ったメモリの解放
//     t_list *current = head;
//     while (current)
//     {
//         t_list *next = current->next;
//         free(current);
//         current = next;
//     }
//     return (0);
// }
