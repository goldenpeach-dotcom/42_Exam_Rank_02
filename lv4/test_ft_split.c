/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:13:06 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/11 20:40:15 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

static int	count_words(const char *str, const char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return ((int)count);
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
	return(word);
}

char	**ft_split(const char *str const char c)
{
	size_t	i;
	size_t	j;
	char	**result;
	
	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!result)
		return (NULL);
	while(str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			result[j] = copy_word(&str[i], c);
			if (!result[j])
				return (free_all(result, j));
			while(str[i] && str[i] != c)
				i++;
			j++;
		}

	}
	result[j] = NULL;
	return (result);
}
