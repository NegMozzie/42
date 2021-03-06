/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 13:02:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		init(t_env *env)
{
	env->posx = 22;
	env->posy = 11.5;
	env->dirx = -1.0;
	env->diry = 0.0;
	env->planex = 0.0;
	env->planey = 0.66;
	env->forward = 0;
	env->back = 0;
	env->left = 0;
	env->right = 0;
}

static int		create_img(t_env *env)
{
	t_img		*img;

	env->img[10] = (t_img *)malloc(sizeof(t_img));
	img = env->img[10];
	if (!(img->img = mlx_new_image(env->ptr, SCREENWIDTH, SCREENHEIGHT)))
		exit (0);
	if (!(img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->sizel)
		, &(img->endian))))
		exit (0);
	return (1);
}

static void		mlx(t_env *e)
{
	mlx_expose_hook(e->win, raycaster, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, key_press, e);
	mlx_hook(e->win, KEYRELEASE, KEYRELEASEMASK, key_release, e);
	mlx_loop_hook(e->ptr, key_hook, e);
	mlx_do_key_autorepeatoff(e->ptr);
	mlx_loop(e->ptr);
}

int				main(int ac, char **argv)
{
	t_env		env;

	if (ac < 2)
		return (0);
	if ((env.ptr = mlx_init()) == NULL)
		return (0);
	if ((env.win = mlx_new_window(env.ptr, SCREENWIDTH, SCREENHEIGHT
		, "Raycaster")) == NULL)
		return (0);
	create_img(&env);
	get_tex(&env);
	init(&env);
	get_map(&env.worldmap, argv[1]);
	mlx(&env);
	return (0);
}
