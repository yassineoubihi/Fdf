/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 20:30:09 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/03 02:03:12 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_line_len(char *str);
char	*ft_line_insert(char *return_line, char *all_line);
char	*line_maker(char *str);
char	*ft_read_lines(int fd, char *all_lines);
char	*get_next_line(int fd);
char	*ft_left_lines(char *all_lines);
char	*ft_strjoin_g(char *left_str, char *buff);

#endif