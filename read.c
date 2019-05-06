/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:27:43 by crenly-b          #+#    #+#             */
/*   Updated: 2019/05/06 12:54:20 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		link_count(char buff[], int i, int *count)
{
	int link;

	link = 0;
	if (i % 5 != 0 && buff[i - 1] == '#')
		link++;
	if (i % 5 != 3 && buff[i + 1] == '#')
		link++;
	if (i / 5 != 0 && buff[i - 5] == '#')
		link++;
	if (i / 5 != 3 && buff[i + 5] == '#')
		link++;
	(*count)++;
	return (link);
}

int		check_tetr(int fd, char **str)
{
	char	buff[21];
	int		count;
	int		link;
	int		i;

	if (read(fd, buff, 20) < 20 || buff[4] != '\n' || buff[9] != '\n'
		|| buff[14] != '\n' || buff[19] != '\n')
		return (0);
	buff[20] = '\0';
	i = -1;
	count = 0;
	link = 0;
	while (++i < 20)
	{
		if (buff[i] == '#' && i % 5 != 4)
			link = link + link_count(buff, i, &count);
		else if ((buff[i] != '.' && i % 5 != 4) || count > 4)
			return (0);
	}
	if ((link != 6 && link != 8) || count != 4)
		return (0);
	*str = ft_strdup(buff);
	return (1);
}

void	ft_begin_lstadd(t_list **alst, t_tetris *tetra)
{
	t_list	*new;
	t_list	*temp;

	if (!alst || !tetra)
		return ;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return ;
	new->content = tetra;
	new->content_size = sizeof(t_tetris);
	new->next = NULL;
	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

int		read_file(int fd, int *count_elem_in_list, t_list **start)
{
	char		c;
	int			res;
	char		*str;
	char		value;
	t_tetris	*tetra;

	value = 'A';
	str = NULL;
	if (fd < 0 || !start)
		return (-1);
	while (check_tetr(fd, &str))
	{
		if ((*count_elem_in_list)++ > 26)
			return (-1);
		tetra = get_piece(str, value++);
		ft_begin_lstadd(start, tetra);
		ft_memdel((void **)&str);
		res = read(fd, &c, 1);
		if ((res == 1 && c != '\n') || res < 0)
			return (-1);
		else if (res == 0)
			return (1);
	}
	return (-1);
}
