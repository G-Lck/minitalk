/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c       ....                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@ent.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:34:05 by glucken           #+#    #+#             */
/*   Updated: 2025/10/03 13:52:13 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ready_to_send = true;

void	send_char_to_bits(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ready_to_send = false;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
		while (g_ready_to_send == false)
			pause();
	}
}

void	handler(int signal)
{
	if (signal == SIGUSR1)
		g_ready_to_send = true;
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	if (argc != 3)
		ft_printf("Error\n");
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_char_to_bits(pid, (unsigned char) argv[2][i]);
			i++;
		}
		send_char_to_bits(pid, '\n');
	}
	return (0);
}
