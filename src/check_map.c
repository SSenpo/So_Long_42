/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:45:35 by mmago             #+#    #+#             */
/*   Updated: 2022/04/11 21:08:42 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	h_w_map(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	if (game->map[h][w])
	{
		while (game->map[h])
			h++;
		while (game->map[0][w])
			w++;
	}
	game->h_map = h;
	game->w_map = w;
	h = 0;
	w = 0;
	while (game->map[h])
	{
		while (game->map[h][w])
			w++;
		if (w != game->w_map)
			ft_error(1, game);
		h++;
		w = 0;
	}
}

void	map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->map[i])
	{
		while ((game->map) && (game->map[(game->h_map) - 1][j]))
		{
			if ((game->map[0][j] != '1')
					|| (game->map[(game->h_map) - 1][j] != '1'))
				ft_error(1, game);
			j++;
		}
		while ((game->map[i]) && (game->map[i][(game->w_map) - 1]))
		{
			if ((game->map[i][0] != '1')
					|| (game->map[i][(game->w_map) - 1] != '1'))
				ft_error(1, game);
			i++;
		}
	}
}

void	character(t_game *game, int i, int j)
{
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'P')
		{
			game->p_x = j;
			game->p_y = i;
			game->count_p++;
		}
		if (game->map[i][j] == 'C')
			game->count_c++;
		if (game->map[i][j] == 'E')
			game->count_e++;
		if (game->map[i][j] == 'V')
			game->count_enemy++;
		if ((game->map[i][j] != '1')
			&& (game->map[i][j] != '0') && (game->map[i][j] != 'P')
			&& (game->map[i][j] != 'C') && (game->map[i][j] != 'E')
			&& (game->map[i][j] != 'V'))
			ft_error(1, game);
		j++;
	}
}

void	map_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->map[i])
	{
		h_w_map(game);
		map_walls(game);
		while (game->map[i])
		{
			character(game, i, j);
			j = 0;
			i++;
		}
		if ((game->count_p != 1) || (game->count_c < 1) || (game->count_e < 1))
			ft_error(1, game);
	}
	else
		ft_error(1, game);
}

void	ft_read_map(t_game *game, char **av)
{
	int	i;

	game->fd = open(av[1], O_RDONLY, 0644);
	if (game->fd < 0)
		ft_error(2, game);
	game->map = malloc(10000);
	if (!(game->map))
		ft_error(4, game);
	i = 0;
	game->map[i] = get_next_line(game->fd);
	while (game->map[i])
	{
		i++;
		game->map[i] = get_next_line(game->fd);
	}
	map_valid(game);
}
