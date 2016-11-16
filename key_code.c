/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 06:49:39 by cglens            #+#    #+#             */
/*   Updated: 2016/09/04 00:58:56 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_color(t_graph *draw, int z0, int z1)
{
	if (z0 + z1 < 0)
		draw->color = 0x0000ff;
	else if (z0 + z1 > 0)
		draw->color = 0xff0000;
	else
		draw->color = 0x00ff00;
}

void	move_map(int move, t_structception *eheh)
{
	t_recup		*map;
	t_graph		*draw;

	map = eheh->map;
	draw = eheh->draw;
	mlx_destroy_image(MLX, IMG);
	if (move == 123)
		OFFSET_X -= 10;
	if (move == 124)
		OFFSET_X += 10;
	if (move == 125)
		OFFSET_Y += 10;
	if (move == 126)
		OFFSET_Y -= 10;
	send_coord(draw, map);
}

void	zoom(int marge, t_structception *eheh)
{
	t_recup		*map;
	t_graph		*draw;

	map = eheh->map;
	draw = eheh->draw;
	mlx_destroy_image(MLX, IMG);
	if (marge == 69 || marge == 24)
		MARGE *= 1.5;
	else if (marge == 78 || marge == 27)
		MARGE *= 0.6;
	send_coord(draw, map);
}

int		event(int key, t_structception *eheh)
{
	if (key == 53)
		exit(1);
	move_map(key, eheh);
	zoom(key, eheh);
	return (0);
}
