/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:43:06 by mkaneko           #+#    #+#             */
/*   Updated: 2026/06/26 18:19:38 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_word(char *s, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &s[start + i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	first_start;
	int	first_len;
	int	word_start;
	int	word_len;
	int	printed;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	printed = 0;
	// 最初の単語を記録
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	first_start = i;
	first_len = 0;
	while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
	{
		first_len++;
		i++;
	}
	// 2番目以降の単語を出力
	while (argv[1][i])
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		word_start = i;
		word_len = 0;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			word_len++;
			i++;
		}
		if (word_len > 0)
		{
			if (printed)
				write(1, " ", 1);
			write_word(argv[1], word_start, word_len);
			printed = 1;
		}
	}
	// 最初の単語を最後に出力
	if (first_len > 0)
	{
		if (printed)
			write(1, " ", 1);
		write_word(argv[1], first_start, first_len);
	}
	write(1, "\n", 1);
	return (0);
}
// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $>
// 方針：
// 1)最初の単語の開始位置と長さを記録
// 2)2番目以降の単語を順番に出力
// 3)最後にスペース + 最初の単語を出力