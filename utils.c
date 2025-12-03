# include "utils.h"

static int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	value;
	int	i;
	int	sign;

	i = 0;
	value = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		value = value * 10 + nptr[i] - '0';
		i++;
	}
	return (sign * value);
}

void	handler(int signal)
{
	int	a;

	a = 0;

	if (a == 0 && signal == SIGUSR1)
	{
		a++;
	}
}

void	send_char_to_bits(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i <= 31)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		signal(SIGUSR1, handler);
		usleep(1000);
	}
}

void	write_bits_to_char(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	bit = 0;
	int			j;

	(void) context;
	j = 1;
	if (signum == SIGUSR1)
	{
		j <<= i;
		bit |= j;
	}
	i++;
	if (i == 32)
	{
		write (1, &bit, 1);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR1);
	}
}
