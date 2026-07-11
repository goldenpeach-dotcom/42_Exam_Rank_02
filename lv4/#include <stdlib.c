#include <stdlib.h>
#include <stdio.h>

static int is_sep(char c)
{
	return(c == ' ' || c == '\t' || c == '\n');
}
static int count_words(char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	whlie(str[i])
	{
		if (str[i] && !is_sep(str[i]))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (i);
}

static char	**free_all(char **arr, int i)
{
	while(i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static char *copy_word(char *str)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while(str[len] && !is_sep(str[len]))
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (0);
}

char	**ft_split(const char *str)
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
	while (str[i])
	{
		if (str[i] && is_sep(str))
			i++;
		else
		{
			result[j] = copy_word(&str[i]);
			if (!result[j])
				return (free_all(result, j));
			while(str[i] && !is_sep(str[i]))
				i++;
			j++;
		}
	}
	result[j] = '\0';
	return (result);
}
