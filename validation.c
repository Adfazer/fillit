/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:25:30 by hcloves           #+#    #+#             */
/*   Updated: 2020/01/23 13:21:02 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_find_sharp(char m[4][4], int i, int j, int *number)
{
	if (j != 3 && m[i][j + 1] == '#')
		(*number)++;
	if (j != 0 && m[i][j - 1] == '#')
		(*number)++;
	if (i != 3 && m[i + 1][j] == '#')
		(*number)++;
	if (i != 0 && m[i - 1][j] == '#')
		(*number)++;
}

int		solve3(char m[4][4])
{
	int	ij[2];
	int	number;
	int	number_resh;

	ij[0] = 0;
	ij[1] = 0;
	number = 0;
	number_resh = 0;
	while (ij[0] != 4)
	{
		if (m[ij[0]][ij[1]] == '#')
		{
			solve_find_sharp(m, ij[0], ij[1], &number);
			number_resh++;
		}
		(ij[1])++;
		if (ij[1] == 4)
		{
			ij[1] = 0;
			(ij[0])++;
		}
	}
	if (number_resh == 4)
		return (number);
	return (0);
}

int		solve2(const char *buf)
{
	char	m[4][4];
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (buf[i] != '\0')
	{
		while (buf[i] != '\n' && buf[i] != '\0')
		{
			m[x][y] = buf[i];
			y++;
			i++;
		}
		y = 0;
		x++;
		i++;
	}
	i = solve3(m);
	if (i >= 6 && i <= 8)
		return (0);
	return (-1);
}

void	solve_flag(int *flag, int ret, char *buf)
{
	int	i;

	i = 0;
	if (((buf[ret] != 10 || buf[ret] != 0) && (buf[ret - 1] != 10)))
		*flag = 1;
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		*flag = 1;
	while (i != 20)
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			*flag = 1;
		i++;
	}
}

int		solveall(int fd)
{
	char	*buf;
	int		flag;
	int		ret;
	int		c_tetr;
	int		w_ret;

	buf = ft_strnew(22);
	flag = 0;
	c_tetr = 0;
	while (((ret = read(fd, buf, 21)) >= 20) && flag == 0)
	{
		solve_flag(&flag, ret, buf);
		if (flag == 0)
			flag = solve2(buf);
		c_tetr++;
		w_ret = ret;
	}
	free(buf);
	if ((c_tetr >= 2 && w_ret >= 21) || (c_tetr == 1 && w_ret >= 21))
		return (-1);
	if ((c_tetr == 0 || c_tetr > 26) || (flag != 0))
		return (-1);
	return (1);
}
