/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:12 by alamy             #+#    #+#             */
/*   Updated: 2018/01/26 13:47:45 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_key_funct(int keycode, t_env *param)
{
	if (keycode == 53)
	{	
		exit(0);
	}
	return(0);
}

void ft_draw_line_horiz(t_map *map, t_env *tmp)
{
	int i;
	int j;
	int x;
	int y;
	int x1;
	int y1;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->lines[i]->lenght - 1)
		{
			x = map->lines[i]->points[j]->x;
			y = map->lines[i]->points[j]->y;
			x1 = map->lines[i]->points[j + 1]->x;
			y1 = map->lines[i]->points[j + 1]->y;
			// ft_putnbr(map->lines[i]->lenght);
			if (j + 1 != map->lines[i]->lenght)
			{
				ft_bresenham(x, y, x1, y1, tmp);
			}
			else
				break;
			j++;
		}
		i++;
	}
}

void ft_draw_line_vertical(t_map *map, t_env *tmp)
{
	int i;
	int j;
	int x;
	int y;
	int x1;
	int y1;
	
	i = 0;
	j = 0;
	while (j < map->lines[i]->lenght)
	{
		while (i < map->nb_line - 1)
		{
			x = map->lines[i]->points[j]->x;
			y = map->lines[i]->points[j]->y;
			x1 = map->lines[i + 1]->points[j]->x;
			y1 = map->lines[i + 1]->points[j]->y;
			if (i + 1 != map->nb_line)
			{
				ft_bresenham(x, y, x1, y1, tmp);
			}
			else
				break;
			i++;
		}
		i = 0;
		j++;
	}
}
