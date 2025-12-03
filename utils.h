#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "libftprintf/libftprintf.h"

int		ft_atoi(const char *nptr);
void	send_char_to_bits(int pid, unsigned char c);
void	write_bits_to_char(int signum, siginfo_t *info, void *context);
void	handler(int signal);

#endif
