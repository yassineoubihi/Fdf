/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 20:30:09 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/04 14:50:43 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

struct		s_points
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		space_between;
	int		screen_x;
	int		screen_y;
	int		the_min;
	int		max_x;
	int		max_y;
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	img;
}			t_mlx;

struct		s_drawline_points
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		error;
	int		e2;
};

struct		s_draw_param
{
	int		x;
	int		y;
	int		x_wall;
	int		y_wall;
};

struct		s_fill_index
{
	int		x_index;
	int		y_index;
};

struct		s_iso_index
{
	int		x_index;
	int		y_index;
	int		x;
	int		y;
};

struct		s_help_to_drwa
{
	int		x;
	int		y;
	int		x1;
	int		y1;
};

struct		s_atoi
{
	int			length;
	int			startindex;
	int			decimalnumber;
	int			i;
	char		currentchar;
	int			digitvalue;
};

struct		s_data_fill
{
	char				**r;
	int					fd;
	char				*s;
	int					x;
	int					y;
};

struct	s_combined
{
	struct s_points	***data;
	t_mlx			*env;
};

int			ft_line_len(char *str);
char		*ft_line_insert(char *return_line, char *all_line);
char		*line_maker(char *str);
char		*ft_read_lines(int fd, char *all_lines);
char		*get_next_line(int fd);
char		*ft_left_lines(char *all_lines);
char		*ft_strjoin_g(char *left_str, char *buff);
void		swap(int *a, int *b);
int			count_rows(char *s);
void		drawline(struct s_help_to_drwa var, int color, t_mlx *env);
void		count_rows_coluns(int *x, int *y, char *argv);
int			func0(const char *s, int i, int neg);
int			ft_atoi_hex(const char *s);
int			ishexdigit(char c);
void		fill_data(struct s_points **data, int c, int r, char *argv);
int			func(char c);
void		allocate_data(struct s_points ***data, char *argv);
void		iso(int *x, int *y, int z);
void		change_data(struct s_points **data, char *argv);
void		iso_maker(struct s_points **data, int x, int y);
void		rotate_x(int *y, int *z);
void		rotate_y(int *x, int *z);
void		rotate_z(int *x, int *y);
void		change_data(struct s_points **data, char *argv);
void		draw(struct s_points **data, char *argv, t_mlx *env);
int			ft_custom_strchr(char *s);
int			ishexdigit(char c);
int			min_calcul(int x, int y);
void		swap(int *a, int *b);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		map_check(char *map);
char		**free_mem_splite(char **tab);
void		check_name(char *map);

#endif