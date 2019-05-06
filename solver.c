/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:16:19 by crenly-b          #+#    #+#             */
/*   Updated: 2019/05/06 12:54:19 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(t_map *map, t_list *list)
{
	t_point		cor;
	t_tetris	*tetr;

	if (list == NULL)
		return (1);
	tetr = list->content;
	cor.x = -1;
	while (++cor.x + tetr->height <= map->size)
	{
		cor.y = -1;
		while (++cor.y + tetr->width <= map->size)
		{
			if (check_capacity(map, tetr, cor.x, cor.y) == 1)
			{
				change_map(map, tetr, cor, tetr->value);
				if (!(solve(map, list->next) == 0))
					return (1);
				change_map(map, tetr, cor, '.');
			}
		}
	}
	return (0);
}
