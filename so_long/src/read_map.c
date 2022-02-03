/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:54:29 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/29 22:54:38 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_itoa_dop(int n, char *str, int i)
{
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	return (ft_itoa_dop(n, str, i));
}

static int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;	

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

static char	**alloc_columns(char *file)
{
	char	**map;
	int		line_count;

	line_count = file_linecount(file);
	if (line_count <= 0)
		return (null_error("open or reading error, the file may not exist"));
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (null_error("malloc error on alloc_map()"));
	return (map);
}

t_prog	*read_map(t_prog *prog, char *file)
{
	int		fd;
	int		i;

	prog->map = alloc_columns(file);
	if (prog->map == NULL)
		return (prog);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &prog->map[i++]))
		;
	prog->map[i] = NULL;
	close(fd);
	return (prog);
}
