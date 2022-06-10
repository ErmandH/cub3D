/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:29:31 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/08 22:35:29 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_point	*find_pos(char **map)
{
	t_point	*pos;
	int		x;
	int		y;

	y = -1;
	pos = (t_point *)malloc(sizeof(t_point));
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				pos->i = x;
				pos->j = y;
				return (pos);
			}
		}
	}
	return (pos);
}

t_point	*find_dir(char **map, t_point *pos)
{
	t_point	*dir;

	dir = (t_point *)malloc(sizeof(t_point));
	if (map[pos->j][pos->i] == 'N')
		dir->angle = -90;
	else if (map[pos->j][pos->i] == 'S')
		dir->angle = 90;
	else if (map[pos->j][pos->i] == 'E')
		dir->angle = 0;
	else if (map[pos->j][pos->i] == 'W')
		dir->angle = 180;
	dir->x = cos(ft_deg2rad(dir->angle));
	dir->y = sin(ft_deg2rad(dir->angle));
	map[pos->j][pos->i] = '0';
	return (dir);
}
