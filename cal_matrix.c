/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:46:30 by alamy             #+#    #+#             */
/*   Updated: 2018/01/26 17:08:45 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vecteur4 ft_cal_translation(t_vecteur4 vecteur2, matrix4_t matrix_translation)
{
	t_vecteur4 vec_translation;

	vec_translation.x1 = (vecteur2.x1 * matrix_translation.m[0][0]) + 
	(vecteur2.y1 * matrix_translation.m[0][1]) + (vecteur2.z1 * matrix_translation.m[0][2])
	+ (vecteur2.w1 * matrix_translation.m[0][3]);
	vec_translation.y1 = (vecteur2.x1 * matrix_translation.m[1][0]) + 
	(vecteur2.y1 * matrix_translation.m[1][1]) + (vecteur2.z1 * matrix_translation.m[1][2])
	+ (vecteur2.w1 * matrix_translation.m[1][3]);
	vec_translation.z1 = (vecteur2.x1 * matrix_translation.m[2][0]) + 
	(vecteur2.y1 * matrix_translation.m[2][1]) + (vecteur2.z1 * matrix_translation.m[2][2])
	+ (vecteur2.w1 * matrix_translation.m[2][3]);
	vec_translation.w1 = (vecteur2.x1 * matrix_translation.m[3][0]) + 
	(vecteur2.y1 * matrix_translation.m[3][1]) + (vecteur2.z1 * matrix_translation.m[3][2])
	+ (vecteur2.w1 * matrix_translation.m[3][3]);
	return(vec_translation);
}

t_vecteur4 ft_cal_rotationX(t_vecteur4 vecteur, matrix4_t matrix_rotationX)
{
	t_vecteur4 vec_rotationX;
	
	vec_rotationX.x1 = (vecteur.x1 * matrix_rotationX.m[0][0]) + 
	(vecteur.y1 * matrix_rotationX.m[0][1]) + (vecteur.z1 * matrix_rotationX.m[0][2])
	+ (vecteur.w1 * matrix_rotationX.m[0][3]);
	vec_rotationX.y1 = (vecteur.x1 * matrix_rotationX.m[1][0]) + 
	(vecteur.y1 * matrix_rotationX.m[1][1]) + (vecteur.z1 * matrix_rotationX.m[1][2])
	+ (vecteur.w1 * matrix_rotationX.m[1][3]);
	vec_rotationX.z1 = (vecteur.x1 * matrix_rotationX.m[2][0]) + 
	(vecteur.y1 * matrix_rotationX.m[2][1]) + (vecteur.z1 * matrix_rotationX.m[2][2])
	+ (vecteur.w1 * matrix_rotationX.m[2][3]);
	vec_rotationX.w1 = (vecteur.x1 * matrix_rotationX.m[3][0]) + 
	(vecteur.y1 * matrix_rotationX.m[3][1]) + (vecteur.z1 * matrix_rotationX.m[3][2])
	+ (vecteur.w1 * matrix_rotationX.m[3][3]);
	return(vec_rotationX);
}

t_vecteur4 ft_cal_rotationY(t_vecteur4 vecteur, matrix4_t matrix_rotationY)
{
	t_vecteur4 vec_rotationY;
	
	vec_rotationY.x1 = (vecteur.x1 * matrix_rotationY.m[0][0]) + 
	(vecteur.y1 * matrix_rotationY.m[0][1]) + (vecteur.z1 * matrix_rotationY.m[0][2])
	+ (vecteur.w1 * matrix_rotationY.m[0][3]);
	// ft_putnbr(vec_rotationY.x1);
	// ft_putchar(' ');
	vec_rotationY.y1 = (vecteur.x1 * matrix_rotationY.m[1][0]) + 
	(vecteur.y1 * matrix_rotationY.m[1][1]) + (vecteur.z1 * matrix_rotationY.m[1][2])
	+ (vecteur.w1 * matrix_rotationY.m[1][3]);
	// ft_putnbr(vec_rotationY.y1);
	// ft_putchar(' ');
	vec_rotationY.z1 = (vecteur.x1 * matrix_rotationY.m[2][0]) + 
	(vecteur.y1 * matrix_rotationY.m[2][1]) + (vecteur.z1 * matrix_rotationY.m[2][2])
	+ (vecteur.w1 * matrix_rotationY.m[2][3]);
	// ft_putnbr(vec_rotationY.z1);
	// ft_putchar(' ');
	vec_rotationY.w1 = (vecteur.x1 * matrix_rotationY.m[3][0]) + 
	(vecteur.y1 * matrix_rotationY.m[3][1]) + (vecteur.z1 * matrix_rotationY.m[3][2])
	+ (vecteur.w1 * matrix_rotationY.m[3][3]);
	// ft_putnbr(vec_rotationY.w1);
	// ft_putchar(' ');
	// ft_putchar('\n');
	return(vec_rotationY);
}

t_vecteur4 ft_cal_rotationZ(t_vecteur4 vecteur, matrix4_t matrix_rotationZ)
{
	t_vecteur4 vec_rotationZ;
	
	vec_rotationZ.x1 = (vecteur.x1 * matrix_rotationZ.m[0][0]) + 
	(vecteur.y1 * matrix_rotationZ.m[0][1]) + (vecteur.z1 * matrix_rotationZ.m[0][2])
	+ (vecteur.w1 * matrix_rotationZ.m[0][3]);
	// ft_putnbr(vec_rotationZ.x1);
	// ft_putchar(' ');
	vec_rotationZ.y1 = (vecteur.x1 * matrix_rotationZ.m[1][0]) + 
	(vecteur.y1 * matrix_rotationZ.m[1][1]) + (vecteur.z1 * matrix_rotationZ.m[1][2])
	+ (vecteur.w1 * matrix_rotationZ.m[1][3]);
	// ft_putnbr(vec_rotationZ.y1);
	// ft_putchar(' ');
	vec_rotationZ.z1 = (vecteur.x1 * matrix_rotationZ.m[2][0]) + 
	(vecteur.y1 * matrix_rotationZ.m[2][1]) + (vecteur.z1 * matrix_rotationZ.m[2][2])
	+ (vecteur.w1 * matrix_rotationZ.m[2][3]);
	// ft_putnbr(vec_rotationZ.z1);
	// ft_putchar(' ');
	vec_rotationZ.w1 = (vecteur.x1 * matrix_rotationZ.m[3][0]) + 
	(vecteur.y1 * matrix_rotationZ.m[3][1]) + (vecteur.z1 * matrix_rotationZ.m[3][2])
	+ (vecteur.w1 * matrix_rotationZ.m[3][3]);
	// ft_putnbr(vec_rotationZ.w1);
	// ft_putchar(' ');
	return(vec_rotationZ);
}
	// ft_putnbr(vecteur.y1);
	// ft_putchar(' ');
	// ft_putchar('\n');
	// ft_putnbr(vecteur2.x1 * matrix_translation.m[0][0]);
	// ft_putstr(" + ");
	// ft_putchar(' ');
	// ft_putnbr(vecteur2.y1 * matrix_translation.m[0][1]);
	// ft_putstr(" + ");
	// ft_putchar(' ');
	// ft_putnbr(vecteur2.z1 * matrix_translation.m[0][2]);
	// ft_putstr(" + ");
	// ft_putchar(' ');
	// ft_putnbr(vecteur2.w1 * matrix_translation.m[0][3]);
	// ft_putchar(' ');
	// ft_putstr(" = ");
	// ft_putnbr(vecteur_final.x1);
	// ft_putchar(' ');

		// ft_putchar('\n');
	// ft_putnbr(vecteur2.x1 * matrix_translation.m[1][0]);
	// ft_putstr(" + ");
	// ft_putchar(' ');
	// ft_putnbr(vecteur2.y1 * matrix_translation.m[1][1]);
	// ft_putstr(" + ");
	// ft_putchar(' ');
	// ft_putnbr(vecteur2.z1 * matrix_translation.m[1][2]);
	// ft_putstr(" + ");
	// ft_putchar(' ');
	// ft_putnbr(vecteur2.w1 * matrix_translation.m[1][3]);
	// ft_putchar(' ');
	// ft_putstr(" = ");
	// ft_putnbr(vecteur_final.y1);
	// ft_putchar(' ');