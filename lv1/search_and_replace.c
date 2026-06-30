#include <unistd.h>

int main(int argc, char **argv)
{
	int	i;
	int	flag;
	int	s_count;
	int	t_count;

	if(argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	s_count = 0;
	while (argv[2][s_count])
		s_count++;
	t_count = 0;
	while(argv[3][t_count])
		t_count++;
	if(t_count != 1 || s_count != 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	// flag = 0;
	// while (argv[1][i])
	// {
	// 	if (argv[1][i] == argv[2][0])
	// 		flag = 1;
	// 	i++;
	// }
	// if (flag != 1)
	// {
	// 	while(argv[1][i])
	// 	{
	// 		write(1, &argv[1][i], 1);
	// 		i++;
	// 	}
	// 	write(1, "\n", 1);
	// 	return (0);
	// }
	while (argv[1][i])
	{
		if (argv[1][i] == argv[2][0])
			write(1, &argv[3][0], 1);
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return(0);
}
