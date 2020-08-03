/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:30:26 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/31 08:07:29 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
int			ft_strchr_new(const char *str);
void		fill_block(char **block, char **buf, int readnum);
char		*fill_line(char **block);
char		*create_new_line(int size, char *p_block);
char		*new_block(int size, char *p_block);

#endif
