/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetraddition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:30:58 by hcloves           #+#    #+#             */
/*   Updated: 2020/01/23 14:20:31 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_to_list(int fd, int *count, t_tetr **tetrominos, char *b)
{
	char	*str;
	char	*buf[22];
	char	**arr;
	int		ret;
	int		i_n;

	ret = 0;
	*count = 0;
	fd = open(b, O_RDONLY);
	buf[0] = "\0";
	while ((ret = read(fd, buf, 21)) > 0)
	{
		i_n = 0;
		str = ft_strnew(0);
		count_tetr(&count, buf, &str, ret);
		arr = ft_strsplit(str, '\n');
		i_n = count_n(str);
		if (*count == 1)
			i_n = 6;
		ft_strdel(&str);
		write_coord_to_tetrominos(&arr, &tetrominos);
		cleararray((void **)arr, i_n - 1);
		(*tetrominos)->next = nlist();
		(*tetrominos) = (*tetrominos)->next;
	}
}

void	tetr_norm_find(int *minx, int *miny, t_tetr ***tetrominos)
{
	int	i;

	(*minx) = (**tetrominos)->x[0];
	(*miny) = (**tetrominos)->y[0];
	i = 1;
	while (i < 4)
	{
		if ((**tetrominos)->x[i] < (*minx))
			(*minx) = (**tetrominos)->x[i];
		if ((**tetrominos)->y[i] < (*miny))
			(*miny) = (**tetrominos)->y[i];
		i++;
	}
}

void	tetr_norm(t_tetr **tetrominos)
{
	int		minx;
	int		miny;
	int		i;
	char	letter;
	int		number;

	letter = 'A';
	number = 1;
	while ((*tetrominos)->next != NULL)
	{
		tetr_norm_find(&minx, &miny, &tetrominos);
		i = 0;
		while (i < 4)
		{
			(*tetrominos)->x[i] -= minx;
			(*tetrominos)->y[i] -= miny;
			i++;
		}
		(*tetrominos)->number = number++;
		(*tetrominos)->c = letter++;
		(*tetrominos) = (*tetrominos)->next;
	}
}

void	count_tetr(int **count, char *buf[22], char **str, int ret)
{
	char	*temp;

	temp = NULL;
	buf[ret] = "\0";
	temp = ft_strjoin((const char *)*str, (const char *)buf);
	ft_strdel(str);
	*str = temp;
	(**count)++;
}

t_tetr	*nlist(void)
{
	t_tetr	*n;

	if (!(n = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	n->next = NULL;
	return (n);
}
