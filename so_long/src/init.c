/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:53:57 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/29 22:53:59 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_size_dop(t_prog *prog, int p_count)
{
	if (prog->map[prog->y][prog->x] == 'P')
	{
		p_count++;
		if (p_count > 1)
			error("more than 2 players");
	}
	if (prog->map[prog->y][prog->x] == 'C')
		prog->col_count++;
	if (prog->map[prog->y][prog->x] == 'F')
		prog->side = 1;
	prog->x++;
	return (p_count);
}

void	check_invalid_map(t_prog prog)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < prog.row)
	{
		j = 0;
		while (j < prog.col)
		{
			if (i == 0 || i + 1 == prog.row)
				if (prog.map[i][j] != '1')
					error("Invalid map");
			if (j == 0 || j + 1 == prog.col)
				if (prog.map[i][j] != '1')
					error("Invalid map");
			j++;
		}
		i++;
	}
}

t_prog	*map_size(t_prog *prog)
{
	int	p_count;

	p_count = 0;
	while (prog->map[prog->y])
	{
		while (prog->map[prog->y][prog->x] == '1' ||
		prog->map[prog->y][prog->x] == 'C'
		|| prog->map[prog->y][prog->x] == 'E' ||
		prog->map[prog->y][prog->x] == '0' ||
		prog->map[prog->y][prog->x] == 'P' ||
		prog->map[prog->y][prog->x] == 'V' || prog->map[prog->y][prog->x] == 'H'
		|| prog->map[prog->y][prog->x] == 'F')
			p_count = map_size_dop(prog, p_count);
		prog->y++;
		prog->col = prog->x;
		prog->x = 0;
	}
	prog->row = prog->y;
	check_invalid_map(*prog);
	return (prog);
}

int	end_program(t_prog *prog)
{
	prog->win = 0;
	exit(0);
}

void	init_img(t_prog *prog)
{
	prog->xpm_1 = mlx_xpm_file_to_image(prog->mlx,
			"./sprites/wall_02.xpm", &prog->height, &prog->weight);
	prog->xpm_c = mlx_xpm_file_to_image(prog->mlx,
			"./sprites/plant_03.xpm", &prog->height, &prog->weight);
	prog->xpm_p = mlx_xpm_file_to_image(prog->mlx,
			"./sprites/player_02.xpm", &prog->height, &prog->weight);
	prog->xpm_e1 = mlx_xpm_file_to_image(prog->mlx,
			"./sprites/door_01.xpm", &prog->height, &prog->weight);
	prog->xpm_e2 = mlx_xpm_file_to_image(prog->mlx,
			"./sprites/door_02.xpm", &prog->height, &prog->weight);
	prog->xpm_f = mlx_xpm_file_to_image(prog->mlx,
			"./sprites/enemy_04.xpm", &prog->height, &prog->weight);
	prog->xpm_end = mlx_xpm_file_to_image(prog->mlx,
			"./sprites/ending.xpm", &prog->height, &prog->weight);
	prog->xpm_cnt = mlx_xpm_file_to_image(prog->mlx,
			"./sprites/counter.xpm", &prog->height, &prog->weight);
}
