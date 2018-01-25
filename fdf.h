/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/01/25 16:28:55 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define WINDOW_L 900
# define WINDOW_H 600
# define TILE_WIDTH 30
# define TILE_HEIGHT 30
# include "mlx.h"
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

typedef struct	s_algob
{
	int		nb_pix_x;
	int		nb_pix_y;
	int		incX;
	int		incY;
}				t_algob;

typedef struct	s_pixel
{
	void *mlx;
	void *win;
	void *img_ptr;
	char *img;
	int bpp;
	int size_bits;
	int endian;
	unsigned int color;
}				t_pixel;

/*PARSING*/
int main(int argc, char **argv);
int ft_nb_line(char **argv);
int	ft_getnbr(char *str);
int ft_lenght(char **str);
void ft_print_tab(t_map *map);
t_points **ft_stock_points(char *line, int index, t_points ***points, t_map *map);

/*IMAGE*/
void ft_begin_fdf(t_map *map, t_pixel *tmp);
void ft_create_image(t_map *map, t_pixel *tmp);
void fill_pixel(t_pixel *tmp, t_map *map);

/*BRESENHAM*/
void ft_draw_line_horiz(t_map *map, t_pixel *tmp);
void ft_draw_line_vertical(t_map *map, t_pixel *tmp);
void print_horiz_line(t_map * map, t_pixel *tmp, int i, int j);
void print_vertical_line(t_map * map, t_pixel *tmp, int i, int j);
void ft_bresenham(int x0, int y0, int x1, int y1, t_pixel *tmp, int z);
void ft_bresenham1(t_algob *b, t_pixel *tmp, int x0, int y0, int z);
void ft_bresenham2(t_algob *b, t_pixel *tmp, int x0, int y0, int z);

/*EVENT*/
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
t_vecteur4 ft_transformation(int x, int y, int z, t_pixel *tmp, t_map *map);
t_vecteur4 ft_cal_trans(t_vecteur4 vecteur2, matrix4_t matrix_translation);
t_vecteur4 ft_cal_rotationX(t_vecteur4 vecteur, matrix4_t matrix_rotationX);
t_vecteur4 ft_cal_rotationY(t_vecteur4 vecteur, matrix4_t matrix_rotationY);
t_vecteur4 ft_cal_rotationZ(t_vecteur4 vecteur, matrix4_t matrix_rotationZ);
void ft_print_matrix(matrix4_t matrix);

#endif
