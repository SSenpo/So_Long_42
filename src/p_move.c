/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:45:45 by mmago             #+#    #+#             */
/*   Updated: 2022/04/11 21:08:51 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	p_move_left(t_game *game)
{
	if ((game->map[game->p_y][game->p_x - 1] == 'C')
		|| (game->map[game->p_y][game->p_x - 1] == '0'))
	{
		if (game->map[game->p_y][game->p_x - 1] == 'C')
			(game->count_c)--;
		game->map[game->p_y][game->p_x] = '0';
		game->map[(game->p_y)][(game->p_x) - 1] = 'P';
		game->p_x = game->p_x - 1;
		ft_printf("MOVE = %d\n", (game->move += 1));
		ft_render(game);
	}
	else if ((game->map[game->p_y][game->p_x - 1] == 'E') && game->count_c == 0)
	{
		game->map[game->p_y][game->p_x] = '0';
		game->map[(game->p_y)][(game->p_x) - 1] = 'P';
		game->p_x = game->p_x - 1;
		ft_printf("MOVE = %d\n", (game->move += 1));
		ft_end(0, game);
	}
	else if (game->map[game->p_y][game->p_x - 1] == 'V')
	{
		ft_end(1, game);
	}
}

void	p_move_right(t_game *game)
{
	if ((game->map[game->p_y][game->p_x + 1] == 'C')
		|| (game->map[game->p_y][game->p_x + 1] == '0'))
	{
		if (game->map[game->p_y][game->p_x + 1] == 'C')
			(game->count_c)--;
		game->map[game->p_y][game->p_x] = '0';
		game->map[(game->p_y)][(game->p_x) + 1] = 'P';
		game->p_x = game->p_x + 1;
		ft_printf("MOVE = %d\n", (game->move += 1));
		ft_render(game);
	}
	else if ((game->map[game->p_y][game->p_x + 1] == 'E') && game->count_c == 0)
	{
		game->map[game->p_y][game->p_x] = '0';
		game->map[(game->p_y)][(game->p_x) + 1] = 'P';
		game->p_x = game->p_x + 1;
		ft_printf("MOVE = %d\n", (game->move += 1));
		ft_end(0, game);
	}
	else if (game->map[game->p_y][game->p_x + 1] == 'V')
	{
		ft_end(1, game);
	}
}

void	p_move_up(t_game *game)
{
	if ((game->map[game->p_y - 1][game->p_x] == 'C')
		|| (game->map[game->p_y - 1][game->p_x] == '0'))
	{
		if (game->map[game->p_y - 1][game->p_x] == 'C')
			(game->count_c)--;
		game->map[game->p_y][game->p_x] = '0';
		game->map[(game->p_y) - 1][(game->p_x)] = 'P';
		game->p_y = game->p_y - 1;
		ft_printf("MOVE = %d\n", (game->move += 1));
		ft_render(game);
	}
	else if ((game->map[game->p_y - 1][game->p_x] == 'E')
		&& game->count_c == 0)
	{
		game->map[game->p_y][game->p_x] = '0';
		game->map[(game->p_y) - 1][(game->p_x)] = 'P';
		game->p_y = game->p_y - 1;
		ft_printf("MOVE = %d\n", (game->move += 1));
		ft_end(0, game);
	}
	else if (game->map[game->p_y - 1][game->p_x] == 'V')
	{
		ft_end(1, game);
	}
}

void	p_move_down(t_game *game)
{
	if ((game->map[game->p_y + 1][game->p_x] == 'C')
		|| (game->map[game->p_y + 1][game->p_x] == '0'))
	{
		if (game->map[game->p_y + 1][game->p_x] == 'C')
			(game->count_c)--;
		game->map[game->p_y][game->p_x] = '0';
		game->map[(game->p_y) + 1][(game->p_x)] = 'P';
		game->p_y = game->p_y + 1;
		ft_printf("MOVE = %d\n", (game->move += 1));
		ft_render(game);
	}
	else if ((game->map[game->p_y + 1][game->p_x] == 'E') && game->count_c == 0)
	{
		game->map[game->p_y][game->p_x] = '0';
		game->map[(game->p_y) + 1][(game->p_x)] = 'P';
		game->p_y = game->p_y + 1;
		ft_printf("MOVE = %d\n", (game->move += 1));
		ft_end(0, game);
	}
	else if (game->map[game->p_y + 1][game->p_x] == 'V')
	{
		ft_end(1, game);
	}
}

void	ft_p_move(int keysum, t_game *game)
{
	if (keysum == 0)
		p_move_left(game);
	if (keysum == 1)
		p_move_down(game);
	if (keysum == 2)
		p_move_right(game);
	if (keysum == 13)
		p_move_up(game);
}
