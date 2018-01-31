/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:15:41 by alamy             #+#    #+#             */
/*   Updated: 2018/01/31 09:57:06 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham1(t_algob *b, t_env *tmp, int x0, int y0)
{
	int i;
	int res;

	i = 1;
	res = b->nb_pix_x / 2;
	while (i <= b->nb_pix_x)
	{
		x0 = x0 + b->incX;
		res = res + b->nb_pix_y;
		if (res >= b->nb_pix_x)
		{
			res = res - b->nb_pix_x;
			y0 = y0 + b->incY;
		}
		fill_pixel(tmp, x0, y0, 0x00FFFF);
		i++;
	}
}

void	ft_bresenham2(t_algob *b, t_env *tmp, int x0, int y0)
{
	int i;
	int res;

	i = 1;
	res = b->nb_pix_y / 2;
	while (i <= b->nb_pix_y)
	{
		y0 = y0 + b->incY;
		res = res + b->nb_pix_x;
		if (res >= b->nb_pix_y)
		{
			res = res - b->nb_pix_y;
			x0 = x0 + b->incX;
		}
		fill_pixel(tmp, x0, y0, 0x00FFFF);
		i++;
	}
}

void ft_bresenham(int x0, int y0, int x1, int y1, t_env *tmp)
{
	t_algob b;

	b.nb_pix_x = x1 - x0;
	b.nb_pix_y = y1 - y0;
	b.incX = (x0 > 0) ? 1 : -1;
	b.incY = (y0 > 0) ? 1 : -1;
	x0 = ft_abs(x0);
	y0 = ft_abs(y0);
	if (b.nb_pix_x > b.nb_pix_y)
		ft_bresenham1(&b, tmp, x0, y0);
	else if (b.nb_pix_x < b.nb_pix_y)
		ft_bresenham2(&b, tmp, x0, y0);
}
