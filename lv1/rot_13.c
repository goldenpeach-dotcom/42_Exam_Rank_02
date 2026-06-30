#include <unistd.h>

int	main(int argc, char	**argv)
{
	int		i;
	char	c;

	i = 0;
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while(argv[1][i])
	{
		c = argv[1][i];
		if(('a' <= c && c <= 'm') || ('A' <= c && c <= 'M'))
			c = c + 13;
		else (('n' <= c && c <= 'z') || ('N' <= c && c <= 'Z'))
			c = c - 13;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : rot_13
// Expected files   : rot_13.c
// Allowed functions: write
// --------------------------------------------------------------------------------
// Write a program that takes a string and displays it, replacing each of its
// letters by the letter 13 spaces ahead in alphabetical order.
// 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
// The output will be followed by a newline.
// If the number of arguments is not 1, the program displays a newline.
// Example:
// $>./rot_13 "abc"
// nop
// $>./rot_13 "My horse is Amazing." | cat -e
// Zl ubefr vf Nznmvat.$
// $>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
// NxwuM mYXVWm , 23l $
// $>./rot_13 | cat -e
// $
// $>
// $>./rot_13 "" | cat -e