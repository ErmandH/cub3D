/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:00:48 by akarahan          #+#    #+#             */
/*   Updated: 2022/06/08 22:35:29 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char *av[])
{
	t_player	*pl;

	if (ac == 2)
	{
		pl = (t_player *)malloc(sizeof(t_player));
		check_extension(av[1]);
		pl->data = parse_map(av[1]);
		pl->mlx = init_mlx();
		init_player(pl);
		draw_screen(pl);
		free_all(pl);
	}
	else
		ft_putendl_fd("Error\nUsage example ./cub3D map.cub", STDERR);
	return (0);
}
