/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:16:19 by crenly-b          #+#    #+#             */
/*   Updated: 2019/04/23 12:18:36 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		solve(t_map *map, t_list *list)
{
	int			i;
	int			j;
	t_tetris	*tetr;

	if (list == NULL)
		return (1);
	tetr = list->content;
	i = 0;
	while (i + tetr->height <= map->size)
	{
		j = 0;
		while (j + tetr->width <= map->size)
		{
			if (check_capacity(map, tetr, i, j) == 1)
			{
				change_map(map, tetr, i, j, tetr->value);
				if (!(solve(map, list->next) == 0))
					return (1);
				change_map(map, tetr, i, j, '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}
