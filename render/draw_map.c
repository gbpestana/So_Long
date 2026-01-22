#include "so_long.h"

void	draw_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			put_pixel(
				&g->img,
				x * TILE_SIZE + j,
				y * TILE_SIZE + i,
				color
			);
			j++;
		}
		i++;
	}
}

static void	draw_tile(t_game *g, int x, int y)
{
	char	tile;

	tile = g->map.grid[y][x];
	if (tile == '1')
		draw_square(g, x, y, 0x333333);
	else if (tile == '0')
		draw_square(g, x, y, 0xAAAAAA);
	else if (tile == 'P')
		draw_square(g, x, y, 0x00FF00);
	else if (tile == 'C')
		draw_square(g, x, y, 0xFFD700);
	else if (tile == 'E')
		draw_square(g, x, y, 0xFF0000);
}

static void	render_row(t_game *g, int y)
{
	int	x;

	x = 0;
	while (x < g->map.width)
	{
		draw_tile(g, x, y);
		x++;
	}
}

void	render_map(t_game *g)
{
	int	y;

	y = 0;
	while (y < g->map.height)
	{
		render_row(g, y);
		y++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	render_moves(g);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
