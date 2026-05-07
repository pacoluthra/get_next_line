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

char	*free_n_join(char *buffer, char *result)
{
	char	*temp;

	temp = ft_strjoin(buffer, result);
	free(buffer);
	return (temp);
}

char	*find_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] != '\n')
		i++;
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	while (buffer[i] != '\n')
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*find_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] || buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (buffer[i] || buffer[i] == '\n')
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
	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, result, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		result[bytes_read] = 0;
		buffer = free_n_join(buffer, result);
		if (buffer == NULL)
		{
			free(result);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(result);
	return (buffer);
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
	line = find_line(buffer);
	buffer = find_next(buffer);
	return (line);
}
