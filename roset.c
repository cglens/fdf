/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niborrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 06:11:32 by niborrel          #+#    #+#             */
/*   Updated: 2016/08/23 15:12:24 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	pixel(t_graph *draw, int xx, int yy)
{
	int color1;
		color1 = mlx_get_color_value(MLX, draw->color);

	if (1 < xx && xx < WIN_X && 1 < yy && yy < WIN_Y)
	{	
		(draw->img->data + yy * draw->img->sizeline + 4 * xx)[0] = color1 >> 16;	
		(draw->img->data + yy * draw->img->sizeline + 4 * xx)[1] = color1 >> 8;	
		(draw->img->data + yy * draw->img->sizeline + 4 * xx)[2] = color1;	
	}
}

void	line(t_graph *draw, int xori, int yori, int xdir, int ydir)
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	x0 = xori;
	y0 = yori;
	x1 = xdir;
	y1 = ydir;
	draw->dx = abs(x1 - x0), draw->sx = x0 < x1 ? 1 : -1;
	draw->dy = abs(y1 - y0), draw->sy = y0 < y1 ? 1 : -1; 
	draw->err = (draw->dx > draw->dy ? draw->dx : -draw->dy)/2;

	while (1)
	{
		pixel(draw, x0, y0);
		if (x0 == x1 && y0 == y1)
			break;
		draw->e2 = draw->err;
		if (draw->e2 > -draw->dx)
		{
			draw->err -= draw->dy;
			x0 += draw->sx;
		}	
		if (draw->e2 < draw->dy)
		{
			draw->err += draw->dx;
			y0 += draw->sy;
		}
	}
}

void	proj(t_graph *draw, float x, float y, int which, int z)
{
	int x_tmp;
	int	y_tmp;

	x_tmp = (x * 2) + OFFSET_X;
	y_tmp = y + (WIN_Y / MARGE) / 2 + OFFSET_Y;
	if (z != 0)
		draw->color = 0xff0000;
	else
		draw->color = 0x00ff00;
	if (which == 0)
	{
		draw->xx0 = ((x_tmp * MARGE) + (y_tmp * MARGE * 2) - 19 * 5 * MARGE);
		draw->yy0 = ((y_tmp * MARGE) - (x_tmp * MARGE / 2) - z * 1 * MARGE / 5);
	}
	else if (which == 1)
	{
		draw->xx1 = ((x_tmp * MARGE) + (y_tmp * MARGE * 2) - 19 * 5 * MARGE);
		draw->yy1 = ((y_tmp * MARGE) - (x_tmp * MARGE / 2) - z * 1 * MARGE / 5);
	}
	else if (which == 2)
	{
		draw->xx2 = ((x_tmp * MARGE) + (y_tmp * MARGE * 2) - 19 * 5 * MARGE);
		draw->yy2 = ((y_tmp * MARGE) - (x_tmp * MARGE / 2) - z * 1 * MARGE / 5);
	}
}

void	set_coord(t_graph *draw, t_recup *map, int xbase, int ybase)
{
	draw->x0 = xbase * MARGE;
	draw->x1 = (xbase + 1) * MARGE;
	draw->y0 = ybase * MARGE;
	draw->y1 = (ybase + 1) * MARGE;
	proj(draw, draw->y0, draw->x0, 0, Z0);
	proj(draw, draw->y0, draw->x1, 1, Z2);
	proj(draw, draw->y1, draw->x0, 2, Z1);
	if (xbase < map->lignes - 1)
	{
		ft_get_color(draw, Z2, Z0);
		line(draw, draw->xx0, draw->yy0, draw->xx1, draw->yy1);
	}
	if (ybase < map->colones - 1)
	{
		ft_get_color(draw, Z1, Z0);
		line(draw, draw->xx0, draw->yy0, draw->xx2, draw->yy2);
	}
}

void	send_coord(t_graph *draw, t_recup *map)
{
	int		i;
	int		j;

	IMG = mlx_new_image(MLX, WIN_X, WIN_Y);
	draw->img->data = mlx_get_data_addr(IMG, &(draw->img->bpp), &(draw->img->sizeline), &(draw->img->endian));
	i = 0;
	while (i < map->lignes)
	{
		j = 0;
		while (j < map->colones)
		{
			if (i < map->lignes)
			{
				Z0 = map->coord[i][j] * 10;
				Z1 = (j < map->colones) ? map->coord[i][j + 1]
					* 10 : map->coord[i][j] * 10;
				Z2 = (i + 1 < map->lignes) ? map->coord[i + 1][j]
					* 10 : map->coord[i][j] * 10;
				set_coord(draw, map, i, j);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
}
