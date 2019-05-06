/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:10:49 by crenly-b          #+#    #+#             */
/*   Updated: 2019/05/06 12:54:23 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	ft_main(fd);
	return (0);
}

void	ft_main(int fd)
{
	t_map	*map;
	t_list	*start;
	int		size;
	int		count;

	count = 0;
	start = NULL;
	if (read_file(fd, &count, &start) != 1)
	{
		ft_putstr("error\n");
		free_lst(&start);
		return ;
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
}
