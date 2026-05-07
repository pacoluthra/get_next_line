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

char	*find_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (buffer == NULL)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (line == NULL)
		return (free(buffer), NULL);
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	return (free(buffer), line);
}

char	*find_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer == NULL)
		return (free(buffer), NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*result;
	int		bytes_read;

	if (buffer == NULL)
		buffer = ft_calloc(1, 1);
	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, result, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(result), free(buffer), NULL);
		result[bytes_read] = 0;
		buffer = ft_strjoin(buffer, result);
		if (buffer == NULL)
			return (free(result), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(result), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	if (buffer[0] == 0)
		return (free(buffer), NULL);
	line = find_line(buffer);
	buffer = find_next(buffer);
	return (line);
}

