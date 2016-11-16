/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:23:41 by cglens            #+#    #+#             */
/*   Updated: 2015/12/06 15:47:52 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		ft_putchar('-');
		i = -n;
	}
	if (i < 10)
		ft_putchar(i + 48);
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}
