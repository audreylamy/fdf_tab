/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:43:03 by alamy             #+#    #+#             */
/*   Updated: 2018/01/25 15:36:59 by alamy            ###   ########.fr       */
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

void ft_begin_fdf(t_map *map, t_pixel *tmp)
{
	tmp->mlx = mlx_init();
	tmp->win = mlx_new_window(tmp->mlx, WINDOW_L, WINDOW_H, "mlx 42");
	// ft_create_image(map, tmp);
	ft_draw_line_horiz(map, tmp);
	ft_draw_line_vertical(map, tmp);
	mlx_key_hook(tmp->win, my_key_funct, 0);
	mlx_loop(tmp->mlx);
}