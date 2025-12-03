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

int	set_bits(int signum)
{
	if (signum == SIGUSR1)
		return (0);
	else if (signum == SIGUSR2)
		return (1);
	return (0);
}


void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *) s;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

char	bits_to_ascii(int *bits)
{
	int i;
	int c;

	i = 7;
	c = 0;
	while (i>=0)
	{
		c = 2 * c + bits[i];
	}
	return ((char) c);

}

void	write_bits_to_char(int signum, siginfo_t *info, void *context)
{
	static int	ix;
	static int	bits[8];
	char	c;

	(void) context;
	bits[ix] = set_bits(signum);
	ix++;
	if (ix == 7)
	{
		c = bits_to_ascii(bits);
		write(1, &c, 1);
		if (c == 0)
			write(1, "\n", 1);
		ix = 0;
		ft_memset(bits, 0, 8);
	}

	kill(info->si_pid, SIGUSR1);
	// exitfailure
}
