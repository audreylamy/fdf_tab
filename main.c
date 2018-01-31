/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/01/31 10:34:11 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char *line;
	t_map *parse;
	int fd;
	t_env *tmp;

	tmp = (t_env*)malloc(sizeof(t_env));
	line = NULL;
	if (argc != 2)
		return(0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	parse = ft_begin_parse(fd, line, argv);
	// ft_print_tab(map);
	ft_begin_fdf(parse, tmp);
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
