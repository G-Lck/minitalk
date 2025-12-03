#ifndef UTILS_H
# define UTILS_H

# define _POSIX_C_SOURCE 200809L

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdbool.h>
# include "libftprintf/libftprintf.h"

int		ft_atoi(const char *nptr);
void	send_char_to_bits(int pid, unsigned char c);
void	write_bits_to_char(int signum, siginfo_t *info, void *context);
void	handler(int signal);

#endif
