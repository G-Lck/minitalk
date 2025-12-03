# include "utils.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		ft_printf("Error\n");
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_char_to_bits(pid, argv[2][i]);
			i++;
		}
		send_char_to_bits(pid, '\n');
	}
	return (0);
}
