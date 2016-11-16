/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:53:38 by cglens            #+#    #+#             */
/*   Updated: 2016/09/04 01:48:09 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		conv_tab(t_recup *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->lignes)
	{
		map->split = ft_strsplit(map->tab[i], ' ');
		if (!(map->coord[i] = (int *)malloc(sizeof(int) * map->colones)))
			return (0);
		j = 0;
		while (j < map->colones)
		{
			map->coord[i][j] = ft_atoi(map->split[j]);
			j++;
		}
		i++;
	}
	return (0);
}

int		recup_map(t_recup *map, int fd, char *av)
{
	char	**tmp;

	fd = open(av, O_RDONLY);
	map->i = 0;
	map->count = 0;
	while (get_next_line(fd, &map->line) != 0)
	{
		if (!(tmp = ft_strsplit(map->line, ' ')))
			return (0);
		map->nb = 0;
		while (tmp[map->nb])
			map->nb++;
		if (map->nb != map->colones && map->count++ != 0)
			return (0);
		map->colones = map->nb;
		if (!(map->tab[map->i] = (char *)malloc(sizeof(char)
						* ft_strlen(map->line))))
			return (0);
		map->tab[map->i] = map->line;
		map->i++;
	}
	if (!(map->coord = (int **)malloc(sizeof(int *) * map->lignes)))
		return (0);
	conv_tab(map);
	return (1);
}

void	create(t_graph *draw, t_recup *map)
{
	int				key;
	t_structception	eheh;

	MLX = mlx_init();
	WIN_X = 2000;
	WIN_Y = 1200;
	OFFSET_X = -50;
	OFFSET_Y = -50;
	MARGE = 5;
	WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "fdf");
	eheh = (t_structception){
		map,
		draw
	};
	send_coord(draw, map);
	mlx_key_hook(WIN, event, &eheh);
	mlx_loop(MLX);
}

int		main(int ac, char *av[])
{
	t_recup	map;
	t_graph	draw;
	int		fd;

	ft_bzero(&map, sizeof(t_recup));
	ft_bzero(&draw, sizeof(t_graph));
	if (check_arg(ac) == 0)
		return (0);
	if (!(draw.img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	if (!(fd = check_open(fd, av[1])))
		return (0);
	while (get_next_line(fd, &(map.line)) != 0)
		map.lignes++;
	if (!(map.tab = (char **)malloc(sizeof(char *) * map.lignes + 1)))
		return (1);
	map.tab[map.lignes] = NULL;
	if (recup_map(&map, fd, av[1]) == 0)
	{
		ft_putendl("Map Error");
		return (0);
	}
	create(&draw, &map);
	return (0);
}
