/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:35:32 by hcloves           #+#    #+#             */
/*   Updated: 2020/01/23 14:20:25 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_t
{
	int			number;
	char		c;
	int			x[4];
	int			y[4];
	struct s_t	*next;
}				t_tetr;

int				main(int a, char **b);
void			ft_dellist(t_tetr *tetrominos);
void			cleararray(void **map, int count);
void			solve_find_sharp(char m[4][4], int i, int j, int *number);
int				solve3(char m[4][4]);
int				solve2(const char *buf);
void			solve_flag(int *flag, int ret, char *buf);
int				solveall(int fd);
void			output(char ***map, int count);
int				set_on_map(char **map, int ij[2], t_tetr *tetr, int count);
void			write_on_map(char ***map, int i, int j, t_tetr *tetrominos);
void			mem_map(char ***map, int count);
int				factorial(int number);
int				vld_ttr_st(char **map, t_tetr *tetr, int count, int ij[2]);
void			map_del_tetr(char **map, int count, t_tetr *tetr);
int				mp_slv(int count, t_tetr *tetrominos, char **map);
void			add_tetr_on_map(int count_m, t_tetr *head);
void			count_tetr(int **count, char *buf[22], char **str, int ret);
void			write_coord_to_tetrominos(char ***arr, t_tetr ***tetrominos);
t_tetr			*nlist(void);
int				count_n(char *str);
void			add_to_list(int fd, int *count, t_tetr **tetrominos, char *b);
void			tetr_norm_find(int *minx, int *miny, t_tetr ***tetrominos);
void			tetr_norm(t_tetr **tetrominos);
int				min_size_map(int count);

#endif
