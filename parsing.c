/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:19:16 by alamy             #+#    #+#             */
/*   Updated: 2018/01/31 10:33:43 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map *ft_begin_parse(int fd, char *line, char **argv)
{	
	t_map *map;
	t_lines *elts;
	t_points **position;
	int index;
	
	index = 0;
	map = (t_map*)malloc(sizeof(t_map));
	map->nb_line = ft_nb_line(argv);
	map->lines = (t_lines**)malloc(sizeof(t_lines) * ft_nb_line(argv));

	while (get_next_line(fd, &line) > 0)
	{	
		elts = (t_lines*)malloc(sizeof(t_lines));
		elts->points = ft_stock_points(line, index, &position, elts);
		map->lines[index] = elts;
		index++;
	}
	return(map);
}

t_points **ft_stock_points(char *line, int index, t_points ***points, t_lines *elts)
{
	int			i;
    int         z;
	int			a;
	char		**str;
	t_points 	*a_points;
    
	i = 0;
    z = 0;
	a = 0;
	str = ft_strsplit(line, ' ');
	elts->lenght = ft_lenght(str);
	(*points) = (t_points**)malloc(sizeof(t_points) * elts->lenght);
    while (str[i] != '\0')
    {
		a_points = (t_points*)malloc(sizeof(t_points));
		a_points->x = i * TILE_WIDTH;
        a_points->y = index * TILE_HEIGHT;
		a_points->w = 1;
		if (ft_strchr(str[i], ',')) 
		{
			a_points->z = ft_getnbr(str[i]);
			a = 0;
			while (str[i][a] != '\0')
			{
				if (str[i][a] == ',')
				{
					a_points->color = &str[i][a + 1];
				}
				a++;
			}
		}
	    else
		{
			a_points->color = "0xFFFFFF";    
			a_points->z = ft_getnbr(str[i]);
		}
		(*points)[i] = a_points;
		i++;
    }
	return(*points);
}
