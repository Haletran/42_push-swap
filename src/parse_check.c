/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:09:34 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/19 18:32:55 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_after_check(int nb_args, int flag, char **src)
{
	int	i;
	int	j;

	i = 1;
	if (flag == 1)
		i = 0;
	if (!src)
		return (0);
	while (i != nb_args)
	{
		j = 0;
		while (src[i][j++])
		{
			if ((src[i][j] == '-' || src[i][j] == '+' ) && src[i][j - 1] != 32)
				return (0);
			else if (src[i][j] == ' ')
				return (0);
		}
		i++;
	}
	if (!src[0])
		return (0);
	return (1);
}

int	verif_input(int nb_args, int flag, char **src)
{
	if (!check_input(nb_args, flag, src))
		return (0);
	else if (!ft_isabove(src))
		return (0);
	else if (!check_list(nb_args, flag, src))
		return (0);
	else if (!(nb_args >= 2))
		return (-1);
	return (1);
}

int	global_check(int size, int flag, char **src)
{
	int	i;

	i = 1;
	if (flag == 1 && src[1])
		i = 0;
	if (verif_input(size, flag, src) == -1)
	{
		if (!check_after_check(size, flag, src))
			return (0);
		return (-1);
	}
	else if (verif_input(size, flag, src) == 0)
		return (0);
	return (1);
}
