/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 22:49:21 by cglens            #+#    #+#             */
/*   Updated: 2016/08/23 15:05:52 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_recup	*recup(t_recup *map)
{
	if (!(map = (t_recup *)malloc(sizeof(t_recup))))
		return (NULL);
	map->tab = NULL;
	map->split = NULL;
	map->line = NULL;
	map->coord = NULL;
	return (map);
}

t_graph	*graph(t_graph *draw)
{
	if (!(draw = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
	img(draw);
	return (draw);
}

t_img	*img(t_graph *draw)
{
	if (!(draw->img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	draw->img->mlx = NULL;
	draw->img->win = NULL;
	draw->img->image = NULL;
	draw->img->image = NULL;
	return (draw->img);
}
