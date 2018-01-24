/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:15:41 by alamy             #+#    #+#             */
/*   Updated: 2018/01/24 18:16:43 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_vertical_line(t_map * map, t_pixel *tmp, int i, int j)
{
	int x0;
	int y0;
	int x1;
	int y1;
	x0 = map->lines[i]->points[j]->x;
	y0 = map->lines[i]->points[j]->y;
	x1 = map->lines[i + 1]->points[j]->x;
	y1 = map->lines[i + 1]->points[j]->y;
	ft_bresenham(x0, y0, x1, y1, tmp);
}

void print_horiz_line(t_map * map, t_pixel *tmp, int i, int j)
{
	int x0;
	int y0;
	int x1;
	int y1;
	x0 = map->lines[i]->points[j]->x;
	y0 = map->lines[i]->points[j]->y;
	x1 = map->lines[i]->points[j + 1]->x;
	y1 = map->lines[i]->points[j + 1]->y;
	ft_bresenham(x0, y0, x1, y1, tmp);
}

void	bresenham1(t_algob *bre, t_pixel *tmp, int x0, int y0)
{
	int i;

	i = 1;
	bre->cumul = bre->nb_pix_x / 2;
	while (i <= bre->nb_pix_x)
	{
		x0 = x0 + bre->xinc;
		bre->cumul = bre->cumul + bre->nb_pix_y;
		if (bre->cumul >= bre->nb_pix_x)
		{
			bre->cumul = bre->cumul - bre->nb_pix_x;
			y0 = y0 + bre->yinc;
		}
		mlx_pixel_put(tmp->mlx, tmp->win, x0, y0, 0xFFFFFF);
		i++;
	}
}

void	bresenham2(t_algob *bre, t_pixel *tmp, int x0, int y0)
{
	int i;

	i = 1;
	bre->cumul = bre->nb_pix_x / 2;
	bre->cumul = bre->nb_pix_y / 2;
	while (i <= bre->nb_pix_y)
	{
		y0 = y0 + bre->yinc;
		bre->cumul = bre->cumul + bre->nb_pix_x;
		if (bre->cumul >= bre->nb_pix_y)
		{
			bre->cumul = bre->cumul - bre->nb_pix_y;
			x0 = x0 + bre->xinc;
		}
		mlx_pixel_put(tmp->mlx, tmp->win, x0, y0, 0xFFFFFF);
		i++;
	}
}

void ft_bresenham(int x0, int y0, int x1, int y1, t_pixel *tmp)
{
	t_algob bre;

	bre.nb_pix_x = x1 - x0;
	bre.nb_pix_y = y1 - y0;
	bre.xinc = -1;
	bre.yinc = -1;
	bre.nb_pix_x = bre.nb_pix_x;
	bre.nb_pix_y = bre.nb_pix_y;
	mlx_pixel_put(tmp->mlx, tmp->win, x0, y0, 0xFFFFFF);
	if (bre.nb_pix_x > bre.nb_pix_y)
		bresenham1(&bre, tmp, x0, y0);
	else
		bresenham2(&bre, tmp, x0, y0);
}
