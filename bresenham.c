/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:15:41 by alamy             #+#    #+#             */
/*   Updated: 2018/01/25 17:30:04 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_vertical_line(t_map * map, t_pixel *tmp, int i, int j)
{
	int x0;
	int y0;
	int x1;
	int y1;
	int z;
	// t_vecteur4 vec_transformation1;
	// t_vecteur4 vec_transformation2;

	x0 = map->lines[i]->points[j]->x;
	y0 = map->lines[i]->points[j]->y;
	x1 = map->lines[i + 1]->points[j]->x;
	y1 = map->lines[i + 1]->points[j]->y;
	z = map->lines[i]->points[j]->z;
	// vec_transformation1 = ft_transformation(x0, y0, z, tmp, map);
	// vec_transformation2 = ft_transformation(x1, y1, z, tmp, map);
	ft_bresenham(x0, y0, x1, y1, tmp, z);
}

void print_horiz_line(t_map * map, t_pixel *tmp, int i, int j)
{
	int x0;
	int y0;
	int x1;
	int y1;
	int z;
	// t_vecteur4 vec_transformation1;
	// t_vecteur4 vec_transformation2;

	x0 = map->lines[i]->points[j]->x;
	y0 = map->lines[i]->points[j]->y;
	x1 = map->lines[i]->points[j + 1]->x;
	y1 = map->lines[i]->points[j + 1]->y;
	z = map->lines[i]->points[j]->z;
	// vec_transformation1 = ft_transformation(x0, y0, z, tmp, map);
	// vec_transformation2 = ft_transformation(x1, y1, z, tmp, map);
	// ft_bresenham(vec_transformation1.x1, vec_transformation1.y1, 
	// vec_transformation2.x1, vec_transformation2.y1, tmp, z);
	ft_bresenham(x0, y0, x1, y1, tmp, z);
}

void	ft_bresenham1(t_algob *b, t_pixel *tmp, int x0, int y0, int z)
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
		mlx_pixel_put(tmp->mlx, tmp->win, x0, y0, 0xFFFFFF);
		i++;
	}
}

void	ft_bresenham2(t_algob *b, t_pixel *tmp, int x0, int y0, int z)
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
		mlx_pixel_put(tmp->mlx, tmp->win, x0, y0, 0xFFFFFF);
		i++;
	}
}

void ft_bresenham(int x0, int y0, int x1, int y1, t_pixel *tmp, int z)
{
	t_algob b;

	b.nb_pix_x = x1 - x0;
	b.nb_pix_y = y1 - y0;
	b.incX = (x0 > 0) ? 1 : -1;
	b.incY = (y0 > 0) ? 1 : -1;
	x0 = ft_abs(x0);
	y0 = ft_abs(y0);
	if (b.nb_pix_x > b.nb_pix_y)
		ft_bresenham1(&b, tmp, x0, y0, z);
	else if (b.nb_pix_x < b.nb_pix_y)
		ft_bresenham2(&b, tmp, x0, y0, z);
}
