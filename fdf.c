/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                           +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:05:59 by cglens            #+#    #+#             */
/*   Updated: 2016/08/23 15:00:43 by cglens           ###   ########.fr       */
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
//////////////////
	i = 0;
	while (i < map->lignes)
	{
		ft_putstr("Coord ");
		ft_putnbr(i + 1);
		ft_putstr(" : ");
		j = 0;
		while (j < map->colones)
		{
			ft_putnbr(map->coord[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int		recup_map(t_recup *map, int fd, char *av)
{
	int		i;
	char	**tmp;

	fd = open(av, O_RDONLY);
	map->colones = 0;
	i = 0;
	while (get_next_line(fd, &map->line) != 0)
	{
		if (!(tmp = ft_strsplit(map->line, ' ')))
			return (0);
		while (tmp[map->colones])
			map->colones++;
		if (!(map->tab[i] = (char *)malloc(sizeof(char) * ft_strlen(map->line))))
			return (0);
		map->tab[i] = map->line;
		i++;
	}
	ft_putstr(" , Colones ");
	ft_putnbr(map->colones);
	ft_putchar('\n');
	if (!(map->coord = (int **)malloc(sizeof(int *) * map->lignes)))
		return (0);
	conv_tab(map);
	return (1);
}

void	create(t_graph *draw, t_recup *map)
{
	int		key;
	t_structception	eheh;
	
	if (!(MLX = mlx_init()))
		exit(1);
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
	t_recup	*map;
	t_graph	*draw;
	int		fd;

	map = NULL;
	draw = NULL;
	if ((!(map = recup(map))))
		return (0);
	if ((!(draw = graph(draw))))
		return (0);
	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	map->lignes = 0;
	while (get_next_line(fd, &map->line) != 0)
		map->lignes++;
	ft_putstr("Lignes ");
	ft_putnbr(map->lignes);
	if (!(map->tab = (char **)malloc(sizeof(char *) * map->lignes + 1)))
		return (1);
	map->tab[map->lignes] = NULL;
	if (recup_map(map, fd, av[1]))
		create(draw, map);
	return (0);
}
