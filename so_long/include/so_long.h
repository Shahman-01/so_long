/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:52:58 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/29 22:53:09 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "string.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define RESET 15
# define ESC 53

typedef struct s_prog
{
	int		move;
	char	**map;
	int		x;
	int		y;
	int		col;
	int		row;
	void	*mlx;
	void	*window;
	int		height;
	int		weight;
	void	*xpm_p;
	void	*xpm_c;
	void	*xpm_1;
	void	*xpm_e1;
	void	*xpm_e2;
	void	*xpm_f;
	void	*xpm_cnt;
	void	*xpm_end;
	int		win;
	int		p_x;
	int		p_y;
	int		f_x;
	int		f_y;
	int		call;
	int		side;
	int		col_count;
}				t_prog;

typedef struct s_count
{
	int	res1;
	int	res2;
	int	i;
	int	j;
}			t_count;

t_prog	*read_map(t_prog *prog, char *file);
void	init_img(t_prog *prog);
int		end_program(t_prog *prog);
t_prog	*map_size(t_prog *prog);
char	*ft_itoa(int nb);
int		render_funk(t_prog *prog);
int		error(char *message);
void	*null_error(char *message);
void	print_warning(char *message);
int		get_next_line(int fd, char **line);
char	*ft_join(char const *s1, char const *s2);
void	render_funk_dop(t_prog *prog, t_count *count);
int		have_n(char *str);
int		len(long nb);
size_t	ft_strlen(const char *s);
void	check_invalid_map(t_prog prog);

#endif
