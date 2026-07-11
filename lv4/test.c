/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:43:32 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/09 22:08:22 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	free_all(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

int	count_words(const char *str)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			
		}
		else
			i++;
	}
	return ((int)count);
}

char	*copy_word(const char *str)
{
	size_t	i;	
	size_t	len;
	char 	*word;
	// int call_count;


	// call_count = 0;
	i = 0;
	len = 0;
	while(str[len] && str[len] != ' ' && str[len] != '\t')
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		// if (call_count == 2)
		// {
		// 	free(word);
		// 	return (NULL);
		// }わざとエラーにして挙動を確認。
		word[i] = str[i];
		i++;
		// call_count++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(const char *str)
{
	size_t	i;
	size_t	j;
	char	**result;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			result[j] = copy_word(&str[i]);
			if (!result[j])
				return(free_all(result, j), NULL);
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			j++;
		}
	}
	result[j] =  NULL;
	return (result);
}

static void	print_result(char **result)
{
	int	i;

	if (!result)
	{
		printf("NULL\n");
		return ;
	}
	i = 0;
	while (result[i])
	{
		printf("[%d]: \"%s\"\n", i, result[i]);
		i++;
	}
	printf("合計 %d 単語\n\n", i);
}


static void	test(char *str)
{
	char	**result;
	int		i;

	printf("入力: %s\n", str);
	result = ft_split(str);
	print_result(result);
	if (result)
	{
		i = 0;
		while (result[i])
			free(result[i++]);
		free(result);
	}
}

int	main(void)
{
	test("hello world foo bar");       // 基本
	test("  hello  world  ");          // 前後・連続スペース
	test("a,b,c");                     // 別の区切り文字
	test("");                          // 空文字列
	test("nospace");                   // 区切り文字なし
	test("///");                       // 区切り文字のみ
	return (0);
}
