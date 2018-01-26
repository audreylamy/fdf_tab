/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:43:03 by alamy             #+#    #+#             */
/*   Updated: 2018/01/26 17:09:49 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void fill_pixel(t_pixel *tmp, t_map *map)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while(i < WINDOW_H)
// 	{
// 		j = -1;
// 		while(j < WINDOW_L)
// 		{
// 			if (j % 2)
// 				((int*)tmp->img)[(i * WINDOW_L) + j] = 0x00FFFF;
// 			else
// 				((int*)tmp->img)[(i * WINDOW_L) + j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void ft_create_image(t_map *map, t_pixel *tmp)
// {
// 	tmp->img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
// 	tmp->img = mlx_get_data_addr(tmp->img_ptr, &tmp->bpp, &tmp->size_bits, &tmp->endian);
// 	fill_pixel(tmp, map);
// 	ft_putchar('A');
// 	// tmp->color = mlx_get_color_value(tmp->mlx, 0xFFFFFF);
// 	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img_ptr, 0, 0);
// 	// mlx_destroy_image(tmp->mlx, tmp->img_ptr);
// }

// t_vecteur4 ft_transformation(int x, int y, int z, int w, int i, t_map *map)
// {
// 	t_vecteur4 	vecteur_trans;
// 	t_vecteur4 	vecteur;
// 	matrix4_t 	m_translation;
// 	matrix4_t 	m_rotationX;
// 	t_vecteur4 	resultat;

// 	vecteur_trans = create_vecteur4((WINDOW_L / 2) - ((map->lines[i]->lenght * TILE_WIDTH) / 2), 
// 	(WINDOW_H / 2) - ((map->nb_line * TILE_HEIGHT) / 2), 0, 1);
// 	m_translation = matrix_translation_center(vecteur_trans);
// 	m_rotationX = matrix_rotationX(45 * PI / 180);

// 	vecteur = create_vecteur4(x, y, z, w);

// 	resultat = m4_mult_pos(vecteur, m_rotationX);
// 	resultat = m4_mult_pos(resultat, m_translation);
// 	return(resultat);
// }

void ft_transform_map(t_map *map, t_env *tmp)
{
	int i;
	int j;
	int x0;
	int y0;
	int z0;
	int w0;
	t_vecteur4 	vecteur_trans;
	matrix4_t 	m_translation;
	matrix4_t 	m_rotationX;
	matrix4_t 	m_rotationZ;
	t_vecteur4 	resultat;


	vecteur_trans = create_vecteur4((WINDOW_L / 2) - ((18 * TILE_WIDTH) / 2), 
	(WINDOW_H / 2) - ((10 * TILE_HEIGHT) / 2), 0, 1);
	m_translation = matrix_translation_center(vecteur_trans);
	m_rotationX = matrix_rotationX(55 * PI / 180);
	m_rotationZ = matrix_rotationZ(4 * PI / 180);
	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->lines[i]->lenght)
		{
			x0 = map->lines[i]->points[j]->x;
			y0 = map->lines[i]->points[j]->y;
			z0 = map->lines[i]->points[j]->z;
			w0 = map->lines[i]->points[j]->w;
	
			resultat = create_vecteur4(x0, y0, z0, w0);

			resultat = ft_cal_rotationX(resultat, m_rotationX);
			resultat = ft_cal_rotationZ(resultat, m_rotationZ);
			resultat = ft_cal_translation(resultat, m_translation);
			// resultat = ft_transformation(x0, y0, z0, w0, i, map);

			map->lines[i]->points[j]->x = resultat.x1;
			map->lines[i]->points[j]->y = resultat.y1;
			map->lines[i]->points[j]->z = resultat.z1;
			map->lines[i]->points[j]->w = resultat.w1;
			j++;
		}
		i++;
	}
	ft_draw_line_horiz(map, tmp);
	ft_draw_line_vertical(map, tmp);
}

void ft_begin_fdf(t_map *map, t_env *tmp)
{
	tmp->mlx = mlx_init();
	tmp->win = mlx_new_window(tmp->mlx, WINDOW_L, WINDOW_H, "mlx 42");
	ft_transform_map(map, tmp);
	// ft_create_image(map, tmp);
	mlx_key_hook(tmp->win, my_key_funct, 0);
	mlx_loop(tmp->mlx);
}