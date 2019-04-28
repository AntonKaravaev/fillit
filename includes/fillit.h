/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:27:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/04/28 04:09:17 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetris
{
	char	**pos;
	int		width;
	int		height;
	char	value;
}				t_tetris;

typedef struct	s_map
{
	int		size;
	char	**array;
}				t_map;

t_tetris		*get_piece(char *str, char value);
int				read_file(int fd, int *count_elem_in_list, t_list **start);
void			t_findminmax(char *str, t_point *min, t_point *max);
t_tetris		*new_tetra(char **pos, int width, int height, char value);
t_point			*point_new(int x, int y);
void			print_map(t_map *map);
int				check_capacity(t_map *map, t_tetris *tetr, int p, int q);
void			change_map(t_map *map, t_tetris *tetr, t_point cor, char c);
int				solve(t_map *map, t_list *list);
t_map			*new_map(int size);
int				main(int ac, char **av);
int				link_count(char buff[], int i, int *count);
int				check_tetr(int fd, char **str);
void			ft_begin_lstadd(t_list **alst, t_tetris *tetra);
void			free_tetra(t_tetris **tetr);
void			free_lst(t_list **alst);
void			free_map(t_map **map);
int				sqrt_top(int nb);
void			ft_main(int fd);

#endif
