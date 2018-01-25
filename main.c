/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/01/25 15:45:16 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_points **ft_stock_points(char *line, int index, t_points ***points, t_map *map)
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
	map->lenght = ft_lenght(str);
	(*points) = (t_points**)malloc(sizeof(t_points) * map->lenght + 1);
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

int	main(int argc, char **argv)
{
	char *line;
	t_map *map;
	t_elts *elts;
	t_points **position;
	t_pixel *tmp;
	int index;
	int fd;

	line = NULL;
	index = 0;
	if (argc != 2)
		return(0);
	tmp = (t_pixel*)malloc(sizeof(t_pixel));
	map = (t_map*)malloc(sizeof(t_map));
	map->nb_line = ft_nb_line(argv);
	map->lines = (t_elts**)malloc(sizeof(t_elts) * ft_nb_line(argv));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while (get_next_line(fd, &line) > 0)
	{	
		elts = (t_elts*)malloc(sizeof(t_elts));
		elts->points = ft_stock_points(line, index, &position, map);
		//elts->len = map->lenght;
		map->lines[index] = elts;
		index++;
	}
	// ft_print_tab(map);
	ft_begin_fdf(map, tmp);
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
