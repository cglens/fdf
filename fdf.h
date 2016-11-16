/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 17:20:33 by cglens            #+#    #+#             */
/*   Updated: 2016/09/04 00:58:54 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# define WIN draw->img->win
# define MLX draw->img->mlx
# define IMG draw->img->image
# define DATA draw->img->data
# define SIZELINE draw->img->sizeline
# define BPP draw->img->bpp
# define WIN_X draw->win_size_x
# define WIN_Y draw->win_size_y
# define MARGE draw->marge
# define Z0 draw->z0
# define Z1 draw->z1
# define Z2 draw->z2
# define OFFSET_X draw->offset_x
# define OFFSET_Y draw->offset_y
# define X_DIR draw->x_dir
# define Y_DIR draw->y_dir

typedef	struct		s_recup
{
	char			**tab;
	char			**split;
	char			*line;
	int				**coord;
	int				lignes;
	int				colones;
	int				i;
	int				nb;
	int				count;
}					t_recup;

typedef struct		s_img
{
	void			*mlx;
	void			*win;
	void			*image;
	int				bpp;
	int				endian;
	int				sizeline;
	char			*data;
}					t_img;

typedef struct		s_graph
{
	t_img			*img;
	int				x0;
	int				y0;
	int				z0;
	int				x1;
	int				y1;
	int				z1;
	int				xx0;
	int				yy0;
	int				xx1;
	int				yy1;
	int				xx2;
	int				yy2;
	int				z2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	int				tmp;
	float			marge;
	int				win_size_x;
	int				win_size_y;
	int				x_dir;
	int				y_dir;
	int				offset_x;
	int				offset_y;
	int				color;
	int				which;
}					t_graph;

typedef struct		s_structception
{
	t_recup			*map;
	t_graph			*draw;
}					t_structception;

int					check_arg(int ac);
int					check_open(int fd, char *file);
int					event(int key, t_structception *eheh);
void				ft_get_color(t_graph *draw, int z0, int z1);
t_img				*img(t_graph *draw);
void				send_coord(t_graph *draw, t_recup *map);

#endif
