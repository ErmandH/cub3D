/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:25:53 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/08 22:35:29 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_up_down(t_player *pl, int dir)
{
	t_point	tmp;

	tmp.x = pl->pos->x + dir * pl->dir->x * 2;
	tmp.y = pl->pos->y + dir * pl->dir->y * 2;
	tile2idx(pl->data, &tmp);
	if (pl->data->map[tmp.j][tmp.i] != '1')
	{
		pl->pos->x = tmp.x;
		pl->pos->y = tmp.y;
		tile2idx(pl->data, pl->pos);
	}
}

void	move_left_right(t_player *pl, int dir)
{
	t_point	tmp;

	tmp.angle = fl_mod_deg(pl->dir->angle + 90);
	tmp.x = pl->pos->x + dir * cos(ft_deg2rad(tmp.angle)) * 2;
	tmp.y = pl->pos->y + dir * sin(ft_deg2rad(tmp.angle)) * 2;
	tile2idx(pl->data, &tmp);
	if (pl->data->map[tmp.j][tmp.i] != '1')
	{
		pl->pos->x = tmp.x;
		pl->pos->y = tmp.y;
		tile2idx(pl->data, pl->pos);
	}
}

void	rotate(t_player *pl, int dir)
{
	pl->dir->angle = fl_mod_deg(pl->dir->angle + dir * 2);
	pl->dir->x = cos(ft_deg2rad(pl->dir->angle));
	pl->dir->y = sin(ft_deg2rad(pl->dir->angle));
}
