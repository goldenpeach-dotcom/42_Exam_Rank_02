/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 02:59:08 by mkaneko           #+#    #+#             */
/*   Updated: 2026/07/14 01:15:55 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s || !accept)
		return (NULL);
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	const char	*result;

// テスト1: 一致あり
	result = ft_strpbrk("hello world", "ow");
	printf("Test1: %s\n", result ? result : "(null)");
	// 期待値: "o world"

	// テスト2: 一致なし
	result = ft_strpbrk("hello", "xyz");
	printf("Test2: %s\n", result ? result : "(null)");
	// 期待値: (null)

	// テスト3: NULLチェック
	result = ft_strpbrk(NULL, "abc");
	printf("Test3: %s\n", result ? result : "(null)");
    // 期待値: (null)
	printf("strpbrk check\n");
    // テスト4: 標準のstrpbrkと比較
	result = strpbrk("hello world", "ow");
	printf("Test1: %s\n", result ? result : "(null)");
	// 期待値: "o world"

	// テスト2: 一致なし
	result = strpbrk("hello", "xyz");
	printf("Test2: %s\n", result ? result : "(null)");
	// 期待値: (null)


    // #include <string.h> して strpbrk() と同じ結果か確認
}


// Assignment name	: ft_strpbrk
// Expected files	: ft_strpbrk.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strpbrk
// (man strpbrk).

// The function should be prototyped as follows:

// char	*ft_strpbrk(const char *s1, const char *s2);
// NAME
//        strpbrk - search a string for any of a set of bytes

// SYNOPSIS
//        #include <string.h>

//        char *strpbrk(const char *s, const char *accept);

// DESCRIPTION
//        The strpbrk() function locates the first occurrence in the string s of any of the bytes in the string accept.

// RETURN VALUE
//        The  strpbrk()  function  returns  a pointer to the byte in s that matches one of the bytes in accept, or NULL if no such
//        byte is found.


