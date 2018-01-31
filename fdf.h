/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/01/31 10:33:21 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define WINDOW_L 800
# define WINDOW_H 600
# define TILE_WIDTH 25
# define TILE_HEIGHT 25
# define PI 3.14159265359
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

typedef struct s_lines
{
	t_points **points;
	int lenght;
}				t_lines;

typedef struct	s_map
{
	t_lines **lines;
	int nb_line;
}				t_map;

typedef struct	s_algob
{
	int		nb_pix_x;
	int		nb_pix_y;
	int		incX;
	int		incY; //icrementation
}				t_algob;

typedef struct	s_img
{
	void *img_ptr;
	int *data;
	int bpp;
	int size_bits;
	int endian;
	unsigned int color;
}				t_img;

typedef struct	s_env
{
	void *mlx;
	void *win;
	t_img *img;
}				t_env;

/*PARSING*/
int main(int argc, char **argv);
int ft_nb_line(char **argv);
int	ft_getnbr(char *str);
int ft_lenght(char **str);
void ft_print_tab(t_map *map);
t_map *ft_begin_parse(int fd, char *line, char **argv);
t_points **ft_stock_points(char *line, int index, t_points ***points, t_lines *elts);

/*IMAGE*/
void ft_begin_fdf(t_map *map, t_env *tmp);
void ft_create_image(t_map *map, t_env *tmp);
void fill_pixel(t_env *tmp, int x, int y, int color);

/*BRESENHAM*/
void ft_transform_map(t_map *map, t_env *tmp);
void ft_draw_line_horiz(t_map *map, t_env *tmp);
void ft_draw_line_vertical(t_map *map, t_env *tmp);
void print_horiz_line(t_map * map, t_env *tmp, int i, int j);
void print_vertical_line(t_map * map, t_env *tmp, int i, int j);
void ft_bresenham(int x0, int y0, int x1, int y1, t_env *tmp);
void ft_bresenham1(t_algob *b, t_env *tmp, int x0, int y0);
void ft_bresenham2(t_algob *b, t_env *tmp, int x0, int y0);

/*EVENT*/
int my_key_funct(int keycode, t_env *param);

/*MATRIX*/
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
matrix4_t  matrix_rotationX(float alpha);
matrix4_t  matrix_rotationY(float alpha);
matrix4_t  matrix_rotationZ(float alpha);
t_vecteur4 create_vecteur4(int x, int y, int z, int w);
t_vecteur4 ft_transformation(int x, int y, int z, int w, int i, t_map *map);
t_vecteur4 ft_cal_translation(t_vecteur4 vecteur2, matrix4_t matrix_translation);
t_vecteur4 ft_cal_rotationX(t_vecteur4 vecteur, matrix4_t matrix_rotationX);
t_vecteur4 ft_cal_rotationY(t_vecteur4 vecteur, matrix4_t matrix_rotationY);
t_vecteur4 ft_cal_rotationZ(t_vecteur4 vecteur, matrix4_t matrix_rotationZ);
void ft_print_matrix(matrix4_t matrix);

#endif
