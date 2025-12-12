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

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdbool.h>
# include "libftprintf/libftprintf.h"

int		ft_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);

#endif
