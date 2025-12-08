# include "utils.h"

void	set_bits(int signum, int *bits, int *ix)
{
	if (signum == SIGUSR1)
		bits[*ix] = 1;
	else if (signum == SIGUSR2)
		bits[*ix] = 0;
	else
		return ;
	(*ix)++;
}

char	bits_to_ascii(int *bits)
{
	int i;
	int c;

	i = 7;
	c = 0;
	while (i >= 0)
	{
		c = 2 * c + bits[i];
		i--;
	}
	return ((char) c);
}

void	write_bits_to_char(int signum, siginfo_t *info, void *context)
{
	static int	ix;
	static int	bits[8];
	char	c;

	(void) context;
	set_bits(signum, bits, &ix);
	if (ix == 8)
	{
		c = bits_to_ascii(bits);
		write(1, &c, 1);
		if (c == 0)
			write(1, "\n", 1);
		ix = 0;
		//ft_memset(bits, 0, sizeof(int) * 8);
	}

	kill(info->si_pid, SIGUSR1);
	// exitfailure
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_sigaction = write_bits_to_char;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = set;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Pid : %d\n", getpid());
	while (1)
		pause();
}
