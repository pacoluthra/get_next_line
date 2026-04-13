/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: fluthra <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/04 15:14:33 by fluthra        #+#    #+#                */
/*   Updated: 2026/04/04 15:21:30 by fluthra        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

size_t  ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);

# endif
