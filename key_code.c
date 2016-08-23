/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 06:49:39 by cglens            #+#    #+#             */
/*   Updated: 2016/08/23 15:00:17 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_map(int move, t_structception *eheh)
{
	t_recup		*map;
	t_graph		*draw;

	map = eheh->map;
	draw = eheh->draw;
	mlx_destroy_image(MLX, IMG);
	if (move == 123)
		OFFSET_X -= 5;
	if (move == 124)
		OFFSET_X += 5;
	if (move == 125)
		OFFSET_Y += 5;
	if (move == 126)
		OFFSET_Y -= 5;
	send_coord(draw, map);
}

void	zoom(int marge, t_structception *eheh)
{
	t_recup		*map;
	t_graph		*draw;

	map = eheh->map;
	draw = eheh->draw;
	if (marge == 69 || marge == 24)
		MARGE *= 1.5;
	else if (marge == 78 || marge == 27)
		MARGE *= 0.6;
}

int		event(int key, t_structception *eheh)
{
	if (key == 53)
		exit(1);
	move_map(key, eheh);
	zoom(key, eheh);
	return (0);
}
