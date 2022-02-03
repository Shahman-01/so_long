/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:53:24 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/29 22:53:38 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Returns 0 printing <message> in red */
int	error(char *message)
{
	printf("\033[0;31m" " Error\n    %s\n" "\033[0m", message);
	exit(0);
}

/* Returns NULL printing <message> in red */
void	*null_error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	exit(0);
}

/* Prints <message> in yellow */
void	print_warning(char *message)
{
	printf("\033[0;33m" " Warning\n %s\n" "\033[0m", message);
}
