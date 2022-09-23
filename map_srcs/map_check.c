/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:12:49 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/23 17:41:21 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "map_util.h"

int	map_check_rectangle(char **map)
{
	size_t	x;
	size_t	y;
	int		i;

	y = 0;
	while (map[y])
		y++;
	if (y < 3)
		return ('N');
	x = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (x != ft_strlen(map[i]))
			return ('N');
		i++;
	}
	return ('Y');
}

int	map_charset_cnt(char **map, t_mapsetcnt *mapsetcnt, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mapsetcnt->floor ++;
			if (map[i][j] == '0')
				mapsetcnt->floor ++;
			if (map[i][j] == '0')
				mapsetcnt->floor ++;
			if (map[i][j] == '0')
				mapsetcnt->floor ++;
			if (map[i][j] == '0')
				mapsetcnt->floor ++;
			else
				return ('N');
			j++;
		}
		i++;
	}
	return ('Y');
}

int	map_check_charset(char **map)
{
	t_mapsetcnt	mapsetcnt;

	ft_memset(&mapsetcnt, 0, sizeof(t_mapsetcnt));
	if (map_charset_cnt(map, &mapsetcnt, 0, 0) == 'N')
		return ('N');
	else if (mapsetcnt.coin == 0)
		return ('N');
	else if (mapsetcnt.exit == 0)
		return ('N');
	else if (mapsetcnt.player == 0)
		return ('N');
	return ('Y');
}

int	map_check_wall(char **map)
{
	int		i;
	size_t	ylast;
	size_t	xlast;

	ylast = 0;
	while (map[ylast])
		ylast++;
	ylast--;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[ylast][i] != '1')
			return ('N');
		i++;
	}
	xlast = ft_strlen(map[0]) - 1;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][xlast] != '1')
			return ('N');
	}
	return ('Y');
}

int	map_check_valid(char **map)
{
	if (map_check_rectangle(map) == 'N')
		return ('N');
	else if (map_check_charset(map) == 'N')
		return ('N');
	else if (map_check_wall(map) == 'N')
		return ('N');
	return ('Y');
}
