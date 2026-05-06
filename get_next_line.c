/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: fluthra <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 16:16:48 by fluthra        #+#    #+#                */
/*   Updated: 2026/04/13 16:17:51 by fluthra        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(char *buffer)
{
	free(buffer);
}
char	*find_next(char *buffer)
{
	
}

char	*find_line(char *buffer)
{
	char	*line;
	int		i;

	if (buffer == NULL)
	{
		free_all(buffer);
		return (NULL);
	}
	i = ft_strlen(buffer);
	line = ft_calloc(i, sizeof(char));
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*result;
	int		bytes_read;

	if (buffer == NULL)
		buffer = ft_calloc(1, 1);
	result = ft_calloc(BUFFER_SIZE, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, result, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free_all(result);
			return (NULL);
		}
		if (ft_strchr(result, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	// read until \n
	buffer = read_file(fd, buffer);
	// store everything after \n
	line = find_line(buffer);
	// move to next line
	buffer = find_next(buffer);
	// return line
	return (line);
}
