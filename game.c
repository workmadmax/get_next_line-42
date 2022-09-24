/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:32:49 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/23 21:31:36 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode(int key, t_game *game)
{
	if (key == 65307)
		exit_game(game);
	if (key == 119)
		move_w(game);
	if (key == 115)
		move_s(game);
	if (key == 100)
		move_d(game);
	if (key == 97)
		move_a(game);
	drawn_map(game);
	return (0);
}

void	init_mlx(t_game *game)
{
	int wid;
	int hei;

	wid = (game->info_map.mapLen) * 30;
	hei = game->info_map.mapHei * 30;
	game->mlx = mlx_init();

	game->win = mlx_new_window(game->mlx, wid, hei, "so_lunga");
	init_img(game);

	drawn_map(game);
	mlx_key_hook(game->win, keycode, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (printf("Error\n"), 1);
	game.argv = argv[1];
	check_ext(argv[1], argc);
	parse_map(&game, argv);
	init_mlx(&game);
	return (0);
}
