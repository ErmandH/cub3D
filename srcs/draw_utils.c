/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:00:31 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/08 22:35:29 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

float	ft_dist(float x, float y)
{
	return (sqrt(1 + (y * y) / (x * x)));
}

float	tfm(int nb, t_map *dt, int x)
{
	if (x)
		return (nb * dt->zoom + dt->shift_x);
	else
		return (nb * dt->zoom + dt->shift_y);
}

int	dtfm(float nb, t_map *dt, int x)
{
	if (x)
		return ((nb - dt->shift_x) / dt->zoom);
	else
		return ((nb - dt->shift_y) / dt->zoom);
}

void	idx2tile(t_map *data, t_point *pt)
{
	pt->x = pt->i * data->zoom + (data->shift_x + data->zoom / 2);
	pt->y = pt->j * data->zoom + (data->shift_y + data->zoom / 2);
}

void	tile2idx(t_map *data, t_point *pt)
{
	pt->i = (pt->x - data->shift_x) / data->zoom;
	pt->j = (pt->y - data->shift_y) / data->zoom;
}
