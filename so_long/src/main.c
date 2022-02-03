/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:54:19 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/29 22:54:21 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_funk_dop(t_prog *prog, int y, int x)
{
	if (prog->map[prog->p_y - y][prog->p_x - x] == '1')
		return (0);
	else if (prog->map[prog->p_y - y][prog->p_x - x] == 'C')
		prog->col_count--;
	else if (prog->map[prog->p_y - y][prog->p_x - x] == 'E')
	{
		if (prog->col_count != 0)
			return (0);
		else
		{
			prog->map[prog->p_y][prog->p_x] = '0';
			prog->col_count = 1;
			prog->win = 1;
			return (0);
		}
	}
	else if (prog->map[prog->p_y - y][prog->p_x - x] == 'F')
		prog->win = -1;
	prog->map[prog->p_y - y][prog->p_x - x] = 'P';
	prog->map[prog->p_y][prog->p_x] = '0';
	prog->move++;
	printf("Move counts: %d\n", prog->move);
	return (0);
}

int	move_funk(int key, t_prog *prog)
{
	if (key == UP)
		move_funk_dop(prog, 1, 0);
	else if (key == RIGHT)
		move_funk_dop(prog, 0, -1);
	else if (key == LEFT)
		move_funk_dop(prog, 0, 1);
	else if (key == DOWN)
		move_funk_dop(prog, -1, 0);
	else if (key == ESC)
		end_program(prog);
	return (0);
}

int	main(int ac, char **av)
{
	t_prog	prog;

	if (ac != 2)
		error("Usage: ./so_long [MAP_FILE.ber]\n");
	prog.col_count = 0;
	prog.move = 0;
	prog.call = 0;
	prog.x = 0;
	prog.y = 0;
	prog.mlx = mlx_init();
	read_map(&prog, av[1]);
	map_size(&prog);
	prog.height = prog.col * 64;
	prog.weight = prog.row * 64;
	prog.window = mlx_new_window(prog.mlx, prog.height, prog.weight, "hello");
	init_img(&prog);
	mlx_hook(prog.window, 17, 0, &end_program, &prog);
	mlx_hook(prog.window, 2, 0, &move_funk, &prog);
	mlx_loop_hook(prog.mlx, &render_funk, &prog);
	mlx_loop(prog.mlx);
}
