/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:05:16 by mmago             #+#    #+#             */
/*   Updated: 2022/04/11 21:08:43 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_map(t_game *game)
{
	if (game->map[game->d][game->f] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img[0],
			game->a, game->s);
	if (game->map[game->d][game->f] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img[1],
			game->a, game->s);
	if (game->map[game->d][game->f] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img[3],
			game->a, game->s);
	if (game->map[game->d][game->f] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img[4],
			game->a, game->s);
	if (game->map[game->d][game->f] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img[2],
			game->a, game->s);
	if (game->map[game->d][game->f] == 'V')
		mlx_put_image_to_window(game->mlx, game->win, game->img[5],
			game->a, game->s);
}

void	ft_render(t_game *game)
{
	game->a = 0;
	game->s = 0;
	game->d = 0;
	game->f = 0;
	while (game->map[game->d])
	{
		while (game->map[game->d][game->f]
			&& game->a <= (game->w_map * 100)
				&& game->s <= (game->h_map * 100))
		{
			ft_render_map(game);
			game->a += 100;
			game->f++;
		}
		game->f = 0;
		game->a = 0;
		game->s += 100;
		game->d++;
	}
}
