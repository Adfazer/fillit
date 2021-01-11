/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:26:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/01/23 13:21:37 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_dellist(t_tetr *tetrominos)
{
	t_tetr	*p;
	t_tetr	*tmp;

	p = NULL;
	p = tetrominos;
	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

void	cleararray(void **map, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
