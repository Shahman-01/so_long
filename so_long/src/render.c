/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:54:57 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/29 22:55:00 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	t_count	end_img(t_prog *prog)
{
	t_count	count;

	mlx_clear_window(prog->mlx, prog->window);
	count.res1 = ((prog->row * 64) - 320) / 2;
	count.res2 = ((prog->col * 64) - 320) / 2;
	count.i = 0;
	count.j = 0;
	return (count);
}

static	void	enemy_move(t_prog *prog)
{
	if (prog->map[prog->f_y + prog->side][prog->f_x] != '0' &&
		prog->map[prog->f_y + prog->side][prog->f_x] != 'P')
		prog->side *= -1;
	if (prog->map[prog->f_y + prog->side][prog->f_x] == '0')
	{
		prog->map[prog->f_y + prog->side][prog->f_x] = 'F';
		prog->map[prog->f_y][prog->f_x] = '0';
	}
	else if (prog->map[prog->f_y + prog->side][prog->f_x] == 'P')
	{
		prog->map[prog->f_y + prog->side][prog->f_x] = 'F';
		prog->map[prog->f_y][prog->f_x] = '0';
		prog->win = -1;
	}
	else
	{
	}
}

static	void	animation(t_prog *prog)
{
	prog->call++;
	if (prog->call % 30 == 0)
	{
		prog->xpm_p = mlx_xpm_file_to_image(prog->mlx,
				"./sprites/player_01.xpm", &prog->height, &prog->weight);
		prog->xpm_c = mlx_xpm_file_to_image(prog->mlx,
				"./sprites/plant_03.xpm", &prog->height, &prog->weight);
		prog->xpm_f = mlx_xpm_file_to_image(prog->mlx,
				"./sprites/enemy_04.xpm", &prog->height, &prog->weight);
		if (prog->side == 1 || prog->side == -1)
			enemy_move(prog);
	}
	else if (prog->call % 15 == 0)
	{
		prog->xpm_p = mlx_xpm_file_to_image(prog->mlx,
				"./sprites/player_02.xpm", &prog->height, &prog->weight);
		prog->xpm_c = mlx_xpm_file_to_image(prog->mlx,
				"./sprites/plant_04.xpm", &prog->height, &prog->weight);
		prog->xpm_f = mlx_xpm_file_to_image(prog->mlx,
				"./sprites/enemy_03.xpm", &prog->height, &prog->weight);
	}
}

void	render_while(t_prog *prog, t_count *count)
{
	while (count->i < prog->row)
	{
		count->j = 0;
		render_funk_dop(prog, count);
		count->i++;
	}
}

int	render_funk(t_prog *prog)
{
	t_count	count;

	mlx_clear_window(prog->mlx, prog->window);
	animation(prog);
	count = end_img(prog);
	mlx_string_put(prog->mlx, prog->window, 24, 20,
		15921152, ft_itoa(prog->move));
	if (prog->win == 1)
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->xpm_end, count.res2, count.res1);
	else if (prog->win == -1)
	{
		prog->xpm_end = mlx_xpm_file_to_image(prog->mlx,
				"./sprites/gameover.xpm", &prog->height, &prog->weight);
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->xpm_end, count.res2, count.res1);
	}
	else
		render_while(prog, &count);
	return (0);
}
