/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:10:49 by crenly-b          #+#    #+#             */
/*   Updated: 2019/04/23 12:32:37 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	t_map	*map;
	t_list	*start;
	int		fd;
	int		size;
	int		count;

	count = 0;
	start = NULL;
	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (read_file(fd, &count, &start) != 1)
	{
		ft_putstr("error\n");
		free_lst(&start);
		exit(1);
	}
	size = sqrt_top(count * 4);
	map = new_map(size);
	while (!solve(map, start))
	{
		free_map(&map);
		map = new_map(size++);
	}
	print_map(map);
	free_lst(&start);
	free_map(&map);
	close(fd);
	return (0);
}
