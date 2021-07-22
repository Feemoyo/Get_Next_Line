/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:08:26 by fmoreira          #+#    #+#             */
/*   Updated: 2021/07/22 19:52:30 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static int	search_line_break(char **saved, size_t *scissor)
{
	int	i;

	if (!*saved)
		return (0);
	i = 0;
	while ((*saved)[i] != '\0')
	{
		if ((*saved)[i] == '\n')
		{
			*scissor = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*cut_line(char **saved, size_t *scissor)
{
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	line = NULL;
	if (!*saved)
		return (NULL);
	tmp = ft_strdup(*saved);
	if (search_line_break(&*saved, &*scissor))
	{
		line = ft_substr(*saved, 0, *scissor + 1);
		free(*saved);
		*saved = ft_substr(tmp, *scissor + 1, ft_strlen(tmp));
	}
	else
	{
		i = ft_strlen(tmp);
		if (i > 0)
			line = ft_substr(tmp, 0, i);
		free(*saved);
		*saved = NULL;
	}
	free(tmp);
	return (line);
}

static void	save_changes(char **saved, char **tmp, char **be_read)
{
	if (!*saved)
		*saved = ft_strdup(*be_read);
	else
	{
		*tmp = ft_strdup(*saved);
		free(*saved);
		*saved = ft_strjoin(*tmp, *be_read);
		free(*tmp);
	}
}

char	*get_next_line(int fd)
{
	size_t		scissor;
	size_t		read_int;
	static char	*saved;
	char		*be_read;
	char		*tmp;

	if (fd < 0 || read(fd, NULL, 0) != 0 || BUFFER_SIZE < 0)
		return (NULL);
	be_read = malloc(BUFFER_SIZE + 1);
	read_int = read(fd, be_read, BUFFER_SIZE);
	scissor = 0;
	while (read_int > 0)
	{
		(be_read)[read_int] = '\0';
		save_changes(&saved, &tmp, &be_read);
		if (search_line_break(&saved, &scissor))
			break ;
		read_int = read(fd, be_read, BUFFER_SIZE);
	}
	free(be_read);
	return (cut_line(&saved, &scissor));
}
