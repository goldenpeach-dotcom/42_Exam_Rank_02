#include <stdlib.h>
#include <stdio.h>

void	pgcd(int a,int b)
{
	int	div;
	int result;

	div = 1;
	result = 0;
	while(a >= div && b >= div)
	{
		if (a % div == 0 && b % div == 0)
			result = div;
		div++;
	}
	printf("%d\n", result);
}

int	main(int argc, char	**argv)
{
	int	i;

	i = 0;
	if (argc == 3 && argv[1] && argv[2])
	{
		pgcd(atoi(argv[1]), atoi(argv[2]));
	}
	return (0);
}