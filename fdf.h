/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 20:30:09 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/18 18:33:44 by youbihi          ###   ########.fr       */
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
# include "mlx.h"
# include <stdio.h>

struct Args
{
    int     x0;
    int     y0;
    int     x1;
    int     y1;
};

struct points
{
    int x;
    int y;
    int z;
    int color;
};


int		ft_line_len(char *str);
char	*ft_line_insert(char *return_line, char *all_line);
char	*line_maker(char *str);
char	*ft_read_lines(int fd, char *all_lines);
char	*get_next_line(int fd);
char	*ft_left_lines(char *all_lines);
char	*ft_strjoin_g(char *left_str, char *buff);
void	swap(int *a, int *b);
int		count_rows(char *s);
void	drawline(void *mlx_ptr, void *win_ptr,int x0, int y0, int x1, int y1);
void	count_rows_coluns(int *c, int *r);
int     func0(const char *s, int i, int neg);
int     ft_atoi_hex(const char *s);
int     isHexDigit(char c);
void    fill_data(struct points **data, int c, int r);
int     func(char c);
void    allocate_data(struct points ***data, int column, int row);

#endif