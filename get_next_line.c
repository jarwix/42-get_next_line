/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:30:18 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/31 08:07:17 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*create_new_line(int size, char *p_block)
{
	char	*newline;
	int		i;

	i = 0;
	if (!(newline = malloc(size + 1)))
		return (NULL);
	while (p_block && p_block[i] != '\n' && p_block[i] != '\0')
	{
		newline[i] = p_block[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char		*create_new_block(int size, char *temp_block)
{
	char	*newblock;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(temp_block);
	if (!(newblock = malloc(len - size + 1)))
		return (NULL);
	if (len != size++)
	{
		while (temp_block[size] != '\0')
			newblock[i++] = temp_block[size++];
		newblock[i] = '\0';
	}
	else
	{
		free(newblock);
		newblock = NULL;
	}
	return (newblock);
}

char		*fill_line(char **block)
{
	char	*line;
	char	*temp_block;
	int		i;

	i = 0;
	temp_block = *block;
	while (temp_block && temp_block[i] != '\n' &&
		temp_block[i] != '\0')
		i++;
	if (!(line = create_new_line(i, temp_block)))
	{
		free(*block);
		return (NULL);
	}
	*block = create_new_block(i, temp_block);
	free(temp_block);
	return (line);
}

void		fill_block(char **block, char **buf, int readnum)
{
	char	*str;
	int		i;
	char	*temp_block;
	char	*temp_buf;

	temp_block = *block;
	temp_buf = *buf;
	i = readnum + ft_strlen(*block) + 1;
	if (!(str = malloc(i)))
		return ;
	i = 0;
	while (temp_block && *temp_block != '\0')
		str[i++] = *temp_block++;
	while (temp_buf && *temp_buf != '\0')
		str[i++] = *temp_buf++;
	str[i] = '\0';
	free(*block);
	*block = str;
}

int			get_next_line(int const fd, char **line)
{
	char		*buf;
	int			readnum;
	static char *block;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((ft_strchr_new(block) == 0) &&
		((readnum = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[readnum] = '\0';
		fill_block(&block, &buf, readnum);
	}
	free(buf);
	if (readnum < 0)
		return (-1);
	*line = fill_line(&block);
	if (!(*line))
		return (-1);
	if (!readnum && !block)
		return (0);
	return (1);
}
