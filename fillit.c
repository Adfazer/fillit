/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:40:55 by hcloves           #+#    #+#             */
/*   Updated: 2020/01/23 14:23:17 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	output(char ***map, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			ft_putchar((*map)[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		min_size_map(int count)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	count = count * 4;
	while ((count < i * i) || (count > j * j))
	{
		i++;
		j++;
	}
	if (count == i * i)
		count = i;
	if (count == j * j)
		count = j;
	if (count > i * i && count < j * j)
		count = j;
	return (count);
}

int		main(int a, char **b)
{
	int		count;
	t_tetr	*tetrominos;
	t_tetr	*head;

	count = 0;
	if (a == 2)
	{
		if ((solveall(open(b[1], O_RDONLY)) == 1))
		{
			if (!(tetrominos = (t_tetr *)malloc(sizeof(t_tetr))))
				return (0);
			tetrominos->next = NULL;
			head = tetrominos;
			close(a);
			add_to_list(1, &count, &tetrominos, b[1]);
			tetrominos = head;
			tetr_norm(&tetrominos);
			add_tetr_on_map(min_size_map(count), head);
			ft_dellist(head);
		}
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "fillit [file]\n", 14);
}
