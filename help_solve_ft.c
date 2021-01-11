/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_solve_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:37:06 by hcloves           #+#    #+#             */
/*   Updated: 2020/01/23 14:34:37 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_coord_to_tetrominos(char ***arr, t_tetr ***tetrominos)
{
	int	i;
	int	j;
	int	figura;

	i = 0;
	figura = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*arr)[i][j] == '#')
			{
				(**tetrominos)->x[figura] = i;
				(**tetrominos)->y[figura] = j;
				figura++;
			}
			j++;
		}
		i++;
	}
}

void	map_del_tetr(char **map, int count, t_tetr *tetr)
{
	int i;
	int j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
		{
			if (map[i][j] == tetr->c)
				map[i][j] = '.';
		}
	}
}

void	mem_map(char ***map, int count)
{
	int	i;
	int	j;

	i = 0;
	(*map) = (char **)malloc(sizeof(char *) * count);
	while (i < count)
	{
		j = 0;
		(*map)[i] = (char *)malloc(sizeof(char *) * count);
		while (j < count)
		{
			(*map)[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		factorial(int number)
{
	if (number > 1)
		return (number * factorial(number - 1));
	return (1);
}

int		count_n(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}
