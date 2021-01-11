/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:35:22 by hcloves           #+#    #+#             */
/*   Updated: 2020/01/23 14:31:29 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		set_on_map(char **map, int ij[2], t_tetr *tetr, int count)
{
	int	s;
	int	ret;

	s = 0;
	ret = 0;
	while (s < 4)
	{
		if (ij[0] + tetr->x[s] < count && ij[1] + tetr->y[s] < count)
		{
			if ((map[ij[0] + tetr->x[s]][ij[1] + tetr->y[s]]) == '.')
				ret++;
		}
		s++;
	}
	if (ret == 4)
		return (1);
	return (0);
}

void	write_on_map(char ***map, int i, int j, t_tetr *tetrominos)
{
	int	s;

	s = 0;
	while (s < 4)
	{
		(*map)[i + tetrominos->x[s]][j + tetrominos->y[s]] = tetrominos->c;
		s++;
	}
}

int		vld_ttr_st(char **map, t_tetr *tetr, int count, int ij[2])
{
	if (set_on_map(map, ij, tetr, count))
	{
		write_on_map(&map, ij[0], ij[1], tetr);
		return (1);
	}
	return (0);
}

int		mp_slv(int count, t_tetr *tetrominos, char **map)
{
	int ij[2];

	ij[0] = 0;
	ij[1] = 0;
	while (ij[0] < count)
	{
		while (ij[1] < count)
		{
			if (tetrominos->next == NULL)
				return (1);
			if (vld_ttr_st(map, tetrominos, count, ij))
			{
				if (mp_slv(count, tetrominos->next, map) == 1)
					return (1);
				else
					map_del_tetr(map, count, tetrominos);
			}
			(ij[1])++;
		}
		ij[1] = 0;
		(ij[0])++;
	}
	return (0);
}

void	add_tetr_on_map(int count_m, t_tetr *head)
{
	char	**map;

	mem_map(&map, count_m);
	if (mp_slv(count_m, head, map) == 1)
	{
		output(&map, count_m);
		cleararray((void **)(map), count_m);
	}
	else
	{
		cleararray((void **)(map), count_m);
		add_tetr_on_map(++count_m, head);
	}
}
