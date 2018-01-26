/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fonction_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:47:27 by alamy             #+#    #+#             */
/*   Updated: 2018/01/26 17:08:53 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

matrix4_t  matrix4(t_matrix m) 
{
    return (matrix4_t)
    {
        {{m.a1, m.a2, m.a3, m.a4},
         {m.b1, m.b2, m.b3, m.b4},
         {m.c1, m.c2, m.c3, m.c4},
         {m.d1, m.d2, m.d3, m.d4}}
    };
}

matrix4_t  matrix_identity(void)
{
    return matrix4((t_matrix)
		{1, 0, 0, 0,
		 0, 1, 0, 0,
		 0, 0, 1, 0,
		 0, 0, 0, 1}
    );
}

/*MATRICE TRANSLATION*/

matrix4_t  matrix_translation_center(t_vecteur4 offset)
{
    return matrix4((t_matrix)
		{1, 0, 0, offset.x1,
		 0, 1, 0, offset.y1,
		 0, 0, 1, offset.z1,
		 0, 0, 0, offset.w1}
    );
}

/*MATRICE ROTATION*/

matrix4_t  matrix_rotationX(float angle)
{
    return matrix4((t_matrix)
		{1, 0, 0, 0,
		 0, cos(angle), -sin(angle), 0,
		 0, sin(angle), cos(angle), 0,
		 0, 0, 0, 1}
    );
}

matrix4_t  matrix_rotationY(float angle)
{
    return matrix4((t_matrix)
		{cos(angle), 0, sin(angle), 0,
		 0, 1, 0, 0,
		 -sin(angle), 0, cos(angle), 0,
		 0, 0, 0, 1}
    );
}

matrix4_t  matrix_rotationZ(float angle)
{
    return matrix4((t_matrix)
		{cos(angle), -sin(angle), 0, 0,
		 sin(angle), cos(angle), 0, 0,
		 0, 0, 1, 0,
		 0, 0, 0, 1}
    );
}

t_vecteur4 create_vecteur4(int x, int y, int z, int w)
{
	t_vecteur4 new_vecteur4;

	new_vecteur4.x1= x;
	new_vecteur4.y1= y;
	new_vecteur4.z1= z;
	new_vecteur4.w1= w;
	return(new_vecteur4);
}

// t_vecteur4 m4_mult_pos(t_vecteur4 position, matrix4_t matrix) 
// {
// 	t_vecteur4 result = create_vecteur4(
// 		matrix.m[0][0] * position.x1 + matrix.m[0][1] * position.y1 + matrix.m[0][2] * position.z1 + matrix.m[0][3] * position.w1,
// 		matrix.m[1][0] * position.x1 + matrix.m[1][1] * position.y1 + matrix.m[1][2] * position.z1 + matrix.m[1][3] * position.w1,
//         matrix.m[2][0] * position.x1 + matrix.m[2][1] * position.y1 + matrix.m[2][2] * position.z1 + matrix.m[2][3] * position.w1,
//         matrix.m[3][0] * position.x1 + matrix.m[3][1] * position.y1 + matrix.m[3][2] * position.z1 + matrix.m[3][3] * position.w1
// 	);	
// 	return result;
// }
