/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:14:09 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 14:12:40 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_ray(t_ray *ray, int x1, int y1, double angle)
{
	ray->x1 = x1;
	ray->y1 = y1;
	ray->x2 = x1 + RAYON * cos(angle);
	ray->y2 = y1 + RAYON * sin(angle);
	ray->dx = absolute(ray->x2 - x1);
	ray->dy = absolute(ray->y2 - y1);
	ray->err = ray->dx - ray->dy;
	if (x1 < ray->x2)
		ray->dir_x = 1;
	else
		ray->dir_x = -1;
	if (y1 < ray->y2)
		ray->dir_y = 1;
	else
		ray->dir_y = -1;
	ray->dist_ray = 0;
}

static void	draw_line(t_mlx *mlx, int x1, int y1, double angle)
{
	t_ray	*ray;
	int		e2;

	ray = &(mlx->raycast);
	init_ray(ray, x1, y1, angle);
	e2 = 2 * ray->err;
	while (1)
	{
		mlx_put_pixel(mlx->img_ray, x1, y1, rgb_to_hex(0, 0, 46, 255));
		if ((x1 == ray->x2 && y1 == ray->y2) || is_wall(mlx, x1, y1))
			break ;
		e2 = 2 * ray->err;
		if (e2 > -ray->dy)
		{
			ray->err -= ray->dy;
			x1 += ray->dir_x;
		}
		if (e2 < ray->dx)
		{
			ray->err += ray->dx;
			y1 += ray->dir_y;
		}
	}
}

static void	delete_line(t_mlx *mlx, int x1, int y1, double angle)
{
	t_ray	*ray;
	int		err;
	int		e2;

	ray = &(mlx->raycast);
	init_ray(ray, x1, y1, angle);
	err = ray->dx - ray->dy;
	e2 = 2 * err;
	while (1)
	{
		mlx_put_pixel(mlx->img_ray, x1, y1, 0x00000000);
		if ((x1 == ray->x2 && y1 == ray->y2) || is_wall(mlx, x1, y1))
			break ;
		e2 = 2 * err;
		if (e2 > -ray->dy)
		{
			err -= ray->dy;
			x1 += ray->dir_x;
		}
		if (e2 < ray->dx)
		{
			err += ray->dx;
			y1 += ray->dir_y;
		}
	}
}

void	draw_beam(t_mlx *mlx, int x1, int y1)
{
	double	angle;
	int		compteur;

	compteur = 0;
	angle = mlx->player->angle - ((FOV / 2) * (M_PI / 180));
	while (angle <= mlx->player->angle + ((FOV / 2) * (M_PI / 180)))
	{
		draw_line(mlx, x1, y1, angle);
		mlx->tab[compteur] = mlx->raycast.dist_ray * cosf((angle
					- mlx->player->angle));
		mlx->tab_wall[compteur].x = mlx->wall_coord.x;
		mlx->tab_wall[compteur].y = mlx->wall_coord.y;
		mlx->tab_wall[compteur].orient = mlx->wall_coord.orient;
		compteur++;
		angle += (FOV * (M_PI / 180) / WIDTH);
	}
}

void	delete_beam(t_mlx *mlx, int x1, int y1)
{
	double	angle;

	angle = mlx->player->angle - ((FOV / 2) * (M_PI / 180));
	while (angle <= mlx->player->angle + ((FOV / 2) * (M_PI / 180)))
	{
		delete_line(mlx, x1, y1, angle);
		angle += (FOV * (M_PI / 180) / WIDTH);
	}
}
