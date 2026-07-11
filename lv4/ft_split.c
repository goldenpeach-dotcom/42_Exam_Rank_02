/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:12:47 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/11 19:51:27 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

//区切り文字が引数にないときは使う
// static int is_sep(char c)
// {
// 	return(c == ' ' || c == '\t' || c == '\n');	
// } 

static int	count_words(const char *str, const char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*copy_word(const char *s, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_all(char **arr, size_t	i)
{
	while(i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *)*(count_words(str, c) + 1));
	if (!result)
	{
		return (NULL);
	}
	while(str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			result[j] = copy_word(&str[i], c);
			if (!result[j])
				return (free_all(result, j));
			while (str[i] && str[i] != c)
				i++;
			j++;
		}
	}	
	result[j] = NULL;
	return (result);
}


// count_words: strとcを受け取り、区切りで区切られた単語の個数を返す。前提:特になし
// copy_word: sは「区切り文字でない文字」から始まっていることが前提。区切りまたは\0までをコピーしたstrdupを返す
// ft_split: 全体を統括。スキップとcopy_word呼び出しの境界を管理する責任者

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


// static void	test(char *str, char c)
// {
// 	char	**result;
// 	int		i;

// 	printf("入力: \"%s\", 区切り文字: '%c'\n", str, c);
// 	result = ft_split(str, c);
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
// 	test("hello world foo bar", ' ');       // 基本
// 	test("  hello  world  ", ' ');          // 前後・連続スペース
// 	test("a,b,c", ',');                     // 別の区切り文字
// 	test("", ' ');                          // 空文字列
// 	test("nospace", ' ');                   // 区切り文字なし
// 	test("///", '/');                       // 区切り文字のみ
// 	return (0);
// }
