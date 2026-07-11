#include <stdlib.h>
#include <stdio.h>

static int	is_sep(char c)
{
	return(c == ' ' || c == '\t' || c == '\n');
}
static int	count_words(const char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] && !is_sep(str[i]))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
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

static char	*copy_word(const char *str)
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
	return (res);
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
		if (str[i] && is_sep(str[i]))
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
	result[j] = NULL;
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

	printf("入力: \"%s\", 区切り文字:\n", str);
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
