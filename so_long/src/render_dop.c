/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_dop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:38:19 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/29 23:38:27 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static	void	render_else_if_dop(t_prog *prog, t_count *count)
{
	if (prog->map[count->i][count->j] == 'E')
	{
		if (prog->col_count != 0)
			mlx_put_image_to_window(prog->mlx, prog->window,
				prog->xpm_e1, count->j * 64, count->i * 64);
		else
			mlx_put_image_to_window(prog->mlx, prog->window,
				prog->xpm_e2, count->j * 64, count->i * 64);
	}
	else if (prog->map[count->i][count->j] == 'F')
	{
		prog->f_y = count->i;
		prog->f_x = count->j;
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->xpm_f, count->j * 64, count->i * 64);
	}
}

static	void	render_else_if(t_prog *prog, t_count *count)
{
	if (prog->map[count->i][count->j] == 'C')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->xpm_c, count->j * 64, count->i * 64);
	else if (prog->map[count->i][count->j] == 'P')
	{
		prog->p_y = count->i;
		prog->p_x = count->j;
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->xpm_p, count->j * 64, count->i * 64);
	}
	else
		render_else_if_dop(prog, count);
}

void	render_funk_dop(t_prog *prog, t_count *count)
{
	while (count->j < prog->col)
	{
		if (prog->map[count->i][count->j] == '1')
		{
			if (count->i == 0 && count->j == 0)
			{
			}
			else
				mlx_put_image_to_window(prog->mlx, prog->window,
					prog->xpm_1, count->j * 64, count->i * 64);
		}
		else
			render_else_if(prog, count);
		count->j++;
	}
}
