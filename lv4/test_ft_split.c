/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:13:06 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/11 23:11:43 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	char	free_all(char **arr, int i)
{
	if(!arr)
		return (NULL);
	while (arr[i])
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static int	count_words(const char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;

	while(str[i] != '\0')
	{
		if(str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
		{
			count++;
			while(str[i] != '\0' && str[i] = ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return((int)count);
}

static char	*copy_word(const char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*word;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	len = 0;
	while(str[len])
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while(str[i] != '\0')
	{
		while(str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		word[j] = str[i];
		i++;
		j++;
	}
	return (word);
}

static char *copy_word(const char *str, const char c)
{
	size_t	i;
	size_t 	j;
	char	*word;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while(str[i] != '\0' && str[i] != c)
		i++;
	word = malloc(i + 1);
	if(!word)
		return (NULL);
	while(i > j)
	{
		word[j] = str[j];
		j++;
	}
	return (word);
}

char	**ft_split(const char *str const char c)
{
	size_t	i;
	size_t	j;
	char	**result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		result[j] = copy_word(&str[i]);
		if (!result[j])
			return (free_all(&result, j), NULL);
		j++;
		i++;
	}
	result[j] = NULL;
	return (result);
}

// static void	print_result(char **result)
// {
// 	int	i;

// 	if (!result)
// 	{
// 		printf("NULL\n");
// 		return ;
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("[%d]: \"%s\"\n", i, result[i]);
// 		i++;
// 	}
// 	printf("合計 %d 単語\n\n", i);
// }


// static void	test(char *str)
// {
// 	char	**result;
// 	int		i;

// 	printf("入力: %s\n", str);
// 	result = ft_split(str);
// 	print_result(result);
// 	if (result)
// 	{
// 		i = 0;
// 		while (result[i])
// 			free(result[i++]);
// 		free(result);
// 	}
// }

// int	main(void)
// {
// 	test("hello world foo bar");       // 基本
// 	test("  hello  world  ");          // 前後・連続スペース
// 	test("a,b,c");                     // 別の区切り文字
// 	test("");                          // 空文字列
// 	test("nospace");                   // 区切り文字なし
// 	test("///");                       // 区切り文字のみ
// 	return (0);
// }

