/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:13:06 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/07 10:38:52 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int		count_words(const char *str);
char	*copy_word(const char *str);
void	free_all(char **arr, size_t i);

char	**ft_split(char	*str)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *)*(count_words(str) + 1));
	if (!result)
		return (NULL);
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else
		{
			result[j] = copy_word(&str[i]);
			if (!result[j])
				return (free_all(result, j), NULL);
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

int count_words(const char *str)
{
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
		{
			count++;
			while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return ((int)count);
}

char	*copy_word(const char *str)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	i = 0;
	while(str[len] && str[len] != ' ' && str[len] != '\t' && str[len] != '\n')
				len++;
	word = malloc(len + 1);
	if(!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}
