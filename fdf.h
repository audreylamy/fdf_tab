/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Deydou <Deydou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/01/23 22:16:50 by Deydou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define WINDOW_L 900
# define WINDOW_H 600
# define TILE_WIDTH 30
# define TILE_HEIGHT 30
# include "minilibx/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

typedef struct s_points
{
	int x;
	int y; 
	int z;
	int w;
	char *color;
}				t_points;

typedef struct s_elts
{
	t_points **points;
	//int len;
}				t_elts;

typedef struct	s_map
{
	t_elts **lines;
	int nb_line;
	int lenght;
}				t_map;

typedef struct	s_pixel
{
	void *mlx;
	void *win;
	void *img;
}				t_pixel;

int main(int argc, char **argv);
int ft_nb_line(char **argv);
int	ft_getnbr(char *str);
int ft_lenght(char **str);
void ft_print_tab(t_map *map);
t_points **ft_stock_points(char *line, int index, t_points ***points, t_map *map);
void ft_draw_point(t_map *map, t_pixel *tmp);
int my_key_funct(int keycode, t_pixel *param);

/*MATRICE*/

typedef struct s_vecteur4
{
	float x1;
	float y1;
	float z1;
	float w1;
}				t_vecteur4;

typedef struct s_matrix t_matrix;
typedef union 
{
	float m[4][4];
    struct	s_matrix
    {
		float a1;
		float a2; 
		float a3;
		float a4;
		float b1;
		float b2; 
		float b3; 
		float b4;
		float c1;
		float c2;
		float c3;
		float c4;
		float d1;
		float d2;
		float d3;
		float d4;
	}	   	t_matrix;
} matrix4_t;

matrix4_t  matrix4(t_matrix m);
matrix4_t  matrix_identity(void);
matrix4_t  matrix_translation_center(t_vecteur4 vecteur);
matrix4_t  matrix_rotationX(int alpha);
matrix4_t  matrix_rotationY(int alpha);
matrix4_t  matrix_rotationZ(int alpha);
t_vecteur4 create_vecteur4(int x, int y, int z, int w);
t_vecteur4 ft_cal_trans(t_vecteur4 vecteur2, matrix4_t matrix_translation);
t_vecteur4 ft_cal_rotationX(t_vecteur4 vecteur, matrix4_t matrix_rotationX);
t_vecteur4 ft_cal_rotationY(t_vecteur4 vecteur, matrix4_t matrix_rotationY);
t_vecteur4 ft_cal_rotationZ(t_vecteur4 vecteur, matrix4_t matrix_rotationZ);
void ft_print_matrix(matrix4_t matrix);

#endif
