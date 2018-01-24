/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:12 by alamy             #+#    #+#             */
/*   Updated: 2018/01/24 18:19:17 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_key_funct(int keycode, t_pixel *param)
{
	if (keycode == 53)
	{	
		exit(0);
	}
	return(0);
}

t_vecteur4 ft_transformation(int x, int y, int z, t_pixel *tmp, t_map *map)
{
	t_vecteur4 vecteur;
	t_vecteur4 vecteur1;
	t_vecteur4 vec_translation1;
	// t_vecteur4 vec_rotationZ;
	// t_vecteur4 vec_rotationY;
	matrix4_t translation;
	// matrix4_t rotationZ;
	// matrix4_t rotationY;

	vecteur = create_vecteur4((WINDOW_L / 2) - ((map->lenght * TILE_WIDTH) / 2), 
	(WINDOW_H / 2) - ((map->nb_line * TILE_HEIGHT) / 2), 0, 1);
	translation = matrix_translation_center(vecteur);
	// rotationZ = matrix_rotationZ((330 * 3.14) / 180);
	// rotationY = matrix_rotationY((45 * 3.14) / 180);
	vecteur1 = create_vecteur4(x, y, z, 1);
	// vec_rotationZ = ft_cal_rotationZ(vecteur1, rotationZ);
	// vec_rotationY = ft_cal_rotationY(vec_rotationZ, rotationY);
	vec_translation1 = ft_cal_trans(vecteur1, translation);
	return(vec_translation1);
}

void ft_draw_point(t_map *map, t_pixel *tmp)
{
	int i;
	int j;
	int x;
	int y;
	int z;
	// t_vecteur4 vec_transformation;
	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->lenght)
		{
			x = map->lines[i]->points[j]->x;
			y = map->lines[i]->points[j]->y;
			z = map->lines[i]->points[j]->z;
			if (j + 1 != map->lenght)
			{
				print_horiz_line(map, tmp, i, j);
			}
			else
				break;
			j++;
		}
		i++;
	}
}
