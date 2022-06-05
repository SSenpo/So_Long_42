/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:44:49 by mmago             #+#    #+#             */
/*   Updated: 2022/06/03 15:27:18 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_null(t_game *game)
{
	game->a = 0;
	game->s = 0;
	game->d = 0;
	game->f = 0;
	game->fd = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->move = 0;
	game->h_map = 0;
	game->w_map = 0;
	game->count_p = 0;
	game->count_c = 0;
	game->count_e = 0;
	game->count_enemy = 0;
	game->game = 0;
	game->map = NULL;
}

void	ft_free(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
		i++;
	while (i >= 0)
	{
		free(game->map[i]);
		i--;
	}
	free(game->map);
	ft_null(game);
	// system("leaks so_long");
}

void	ft_error(int i, t_game *game)
{
	if (i == 1)
	{
		ft_putstr_fd("Error: Not a valid map\n", 2);
		ft_free(game);
		exit(0);
	}
	if (i == 2)
	{
		ft_putstr_fd("Error: No map found\n", 2);
		exit(0);
	}
	if (i == 3)
	{
		ft_putstr_fd("Error: Incorrect number of arguments\n", 2);
		exit(0);
	}
	if (i == 4)
	{
		ft_putstr_fd("Error: Malloc not allocate\n", 2);
		ft_free(game);
		exit(0);
	}
}

int	ft_close(t_game *game)
{
	ft_printf("EXIT GAME\n");
	mlx_destroy_window(game->mlx, game->win);
	ft_free(game);
	exit(0);
}

int	ft_end(int i, t_game *game)
{
	if (i == 1)
	{
		game->game = 1;
		ft_printf("YOU DIED!\n");
	}
	else
	{
		game->game = 2;
		ft_printf("YOU WINNER!\n");
	}
	return (0);
}
