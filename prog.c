/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:27:41 by crenly-b          #+#    #+#             */
/*   Updated: 2019/05/06 12:54:22 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr((map->array)[i]);
		ft_putchar('\n');
		i++;
	}
}

int		check_capacity(t_map *map, t_tetris *tetr, int p, int q)
{
	int i;
	int j;

	i = 0;
	while (i < tetr->height)
	{
		j = 0;
		while (j < tetr->width)
		{
			if (tetr->pos[i][j] == '#' && (map->array)[p + i][q + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	change_map(t_map *map, t_tetris *tetr, t_point coordinations, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetr->height)
	{
		j = 0;
		while (j < tetr->width)
		{
			if (tetr->pos[i][j] == '#')
				(map->array)[coordinations.x + i][coordinations.y + j] = c;
			j++;
		}
		i++;
	}
}

int		sqrt_top(int nb)
{
	int sqrt;

	sqrt = 0;
	while (sqrt * sqrt < nb)
		sqrt++;
	return (sqrt);
}

t_map	*new_map(int size)
{
	int		i;
	int		j;
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->array = (char**)ft_memalloc(sizeof(char*) * size + 1)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (!(map->array[i] = ft_strnew(size + 1)))
			return (NULL);
		j = -1;
		while (++j < size)
			map->array[i][j] = '.';
	}
	map->size = size;
	return (map);
}
