/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c       ....                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@ent.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:34:05 by glucken           #+#    #+#             */
/*   Updated: 2025/10/03 13:52:13 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

unsigned char	bits_to_unsignedchar(int *bits)
{
	int	i;
	int	c;

	i = 7;
	c = 0;
	while (i >= 0)
	{
		c = 2 * c + bits[i];
		i--;
	}
	return ((unsigned char) c);
}

void	write_bits_to_char(int signum, siginfo_t *info, void *context)
{
	static int		ix;
	static int		bits[8];
	unsigned char	c;

	(void) context;
	set_bits(signum, bits, &ix);
	if (ix == 8)
	{
		c = bits_to_unsignedchar(bits);
		write(1, &c, 1);
		if (c == 0)
			write(1, "\n", 1);
		ix = 0;
	}
	kill(info->si_pid, SIGUSR1);
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
