/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 01:10:57 by cglens            #+#    #+#             */
/*   Updated: 2016/09/04 01:53:11 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_arg(int ac)
{
	if (ac != 2)
	{
		ft_putstr("Param Error");
		return (0);
	}
	return (1);
}

int		check_open(int fd, char *file)
{
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr("Acces Error");
		return (0);
	}
	return (fd);
}
