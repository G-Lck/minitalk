/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h       ..                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@ent.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:34:05 by glucken           #+#    #+#             */
/*   Updated: 2025/10/03 13:52:13 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _DEFAULT_SOURCE

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdbool.h>
# include "libftprintf/libftprintf.h"

//-------utils-------//

int				ft_atoi(const char *nptr);
void			*ft_memset(void *s, int c, size_t n);

//-------server------//

void			set_bits(int signum, int *bits, int *ix);
unsigned char	bits_to_unsignedchar(int *bits);
void			write_bits_to_char(int signum, siginfo_t *info, void *context);

//------client-----//

void			send_char_to_bits(int pid, unsigned char c);
void			handler(int signal);

#endif
