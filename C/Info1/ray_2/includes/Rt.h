/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:10:47 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 18:03:44 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <X11/Xlib.h>
# include <fcntl.h>
# include "libft.h"

# define	SCREEN_W 640
# define	FOV 	 60
# define	SCREEN_H 480
# define	SPHERE   1
# define	PLAN	 2
# define	MAX_DIST 655350
# define	KS_CONST 1.0
# define	PI 		 3.14159265359
# define	MAX_RECURSION_DEPTH 4
# define	MAX_V_DIST 600.0
# define	EPSILON 0.000001
# define	SQUARE(x) ((x)*(x))
# define	MIN(a,b) (((a)<(b))?(a):(b))
# define	MAX(a,b) (((a)>(b))?(a):(b))
# define	LIMIT(val, min, max) ((val) > (max) ? (max) : ((val) < (min) ? (min) : (val)))
# define	STREQ(a,b) (strcmp(a,b) == 0)

# define UP				65362
# define DOWN			65364
# define LEFT			65361
# define RIGHT			65363

# define	COLOR_BLACK  color_makeFromRGBhex(0x000000)
# define	COLOR_WHITE color_makeFromRGBhex(0xFFFFFF)
# define	COLOR_RED   color_makeFromRGBhex(0xFF0000)
# define	COLOR_GREEN color_makeFromRGBhex(0x00FF00)
# define	COLOR_BLUE  color_makeFromRGBhex(0x0000FF)
# define	COLORS2_RED    color_makeFromRGBhex(0xC00F12)
# define	COLORS2_ORANGE color_makeFromRGBhex(0xD27701)
# define	COLOR_YELLOW  color_makeFromRGBhex(0xFFFF00)
# define	COLORS2_GREEN color_makeFromRGBhex(0x007A28)
# define	COLORS2_BLUE   color_makeFromRGBhex(0x3B9B95)

typedef struct		s_lex
{
	char			*str;
	struct s_lex	*next;
	struct s_lex	*prev;
}					t_lex;

typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
	float			d;
}					t_vect;

typedef struct		s_cam
{
	t_vect		pos;
	t_vect		lookat;
	t_vect		up;
	t_vect		screen;
	t_vect		upleft;
	t_vect		upright;
	t_vect		center;
	t_vect		dir;
	t_vect		right;
	double		focal;
	int 		fov;
	double		width;
	double		height;
}					t_cam;

typedef struct 		s_scene
{
	int 		type;
	t_vect		pos;
	t_vect		dir;
	float		size;
	t_vect 		color;
	double 		reflect;
	double		spec;
	double		pow;
	double 		noise;
	double 		diff;
	struct s_scene 	*next;
} 					t_scene;

typedef struct		s_light
{
	t_vect			pos;
	t_vect			dir;
	t_vect			color;
	float			i;
	struct s_light	*next;
}				t_light;

typedef struct s_tracing
{
	t_scene		*scene;
	double		dist;
}				t_tracing;

typedef struct	s_shading
{
	double		diff;
	double		spec;
}				t_shading;


typedef struct		s_ray
{
	t_vect			orig;
	t_vect			dir;
}					t_ray;

typedef struct	s_env
{
	void		*ptr;
	void		*win;

	void		*img;
	char		*data;
	int			sizel;
	int			endian;
	int			bpp;

	t_ray		ray;
	t_cam		cam;
	t_light		*light;
	t_scene		*scene;
	t_vect		back_color;
	double		aa;
	double		at;
	double		amb;

	int 		forward;
}				t_env;

/*
**
*** PARSER FUNTIONS
**
*/

double			get_nbr(char *str);
t_lex			*get_pos(t_vect *v, t_lex *lex);
t_lex			*get_file(char *file);
t_lex			*get_cam(t_cam *cam, t_lex *lex);
t_lex			*get_plan(t_scene *scene, t_lex *lex);
t_lex			*get_sphere(t_scene *scene, t_lex *lex);
t_lex			*get_obj(t_env *env, t_lex *lex);
t_lex			*get_light(t_light *light, t_lex *lex);
void			ft_init(t_env *env, char *file);
void			cam_setup(t_cam *c);
t_scene			*new_scene();


/*
**
*** vector FUNTIONS
**
*/

double		som(t_vect vect);
t_vect		rot(t_vect v, t_vect r);
t_vect		fab(t_vect v);
double		invsqrt_1(double y);
t_vect		add2(t_vect a, t_vect b, t_vect c);
double		dot(t_vect a, t_vect b);
t_vect		sub(t_vect a, t_vect b);
t_vect		mult2(t_vect v, double b);
t_vect		divi(t_vect v, double b);
double		length(t_vect v);
t_vect		unit(t_vect v);
t_vect		cross(t_vect a, t_vect b);
t_vect		negate(t_vect v);
t_vect		new(int x, int y, int z);
t_vect		dupl(t_vect tmp);
t_vect		add(t_vect vect, t_vect vect1);
t_vect		mult(t_vect vect, t_vect vect1);
t_vect		square(t_vect vect);
t_vect		normal(t_vect v);

/*
**
*** RAY FUNTIONS
**
*/

void		put_vect(char *str, t_vect v);
t_ray		new_ray(t_vect orig, t_vect dir);
t_ray		pixel(t_cam *c, double x, double y);
t_vect		raytrace(t_ray *ray, t_env *env);
t_tracing	ray_once(t_ray *ray, t_env *env);
t_ray		ray_addnoise(t_ray *ray, double epsilon);
t_vect		get_norm(t_scene *scene, t_vect point);
t_ray		ray_reflect(t_vect *dir, t_scene *scene, t_vect point);
t_vect		reflected_ray(t_vect *dir, t_scene *scene, t_vect point);
t_vect		ray_shad(t_ray *ray, t_env *env, t_scene *scene, t_vect point, t_vect color);
int			hitSphere(t_ray *ray, t_scene *sphere, double *dist);
int			sphere_inter(t_ray *ray, t_scene *sphere, double *dist);
int			inter_center(t_ray *ray, t_scene *scene, double *dist);
int			hitplan(t_ray *ray, t_scene *scene, double *distance);

/*
**
*** COLOR FUNTIONS
**
*/

t_vect		c_addweighted(t_vect a, double w, t_vect b, double w1);
t_vect		color_blend(t_vect a, double w, t_vect b);
t_vect		color_makeFromRGBhex(unsigned int c);
t_vect		get_color(t_vect color, t_shading light, double amb);

t_vect			light_dir(t_light *light, t_vect point);
t_vect			light_diff(t_light *light, t_scene *scene, t_vect point, double dist);
t_vect			light_spec(t_light *light, t_ray *ray, t_scene *scene, t_vect point, double dist);


/*
**
*** vector FUNTIONS
**
*/
int			expose(t_env *env);
int			forward(t_env *env);
int			ft_key_release(int keycode, t_env *env);
int			ft_key_press(int keycode, t_env *env);

#endif
