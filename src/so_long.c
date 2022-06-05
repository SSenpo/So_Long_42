/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:45:13 by mmago             #+#    #+#             */
/*   Updated: 2022/04/11 21:08:52 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_null(&game);
	if (ac > 1)
	{
		ft_read_map(&game, av);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.w_map * 100, game.h_map * 100,
				"so_long");
		ft_img_init(&game);
		ft_render(&game);
		mlx_hook(game.win, 2, (1L << 0), key_hook, &game);
		mlx_hook(game.win, 17, 0, ft_close, &game);
		mlx_loop_hook(game.mlx, t_anim, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_error(3, &game);
	return (0);
}
