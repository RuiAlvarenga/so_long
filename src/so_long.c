/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:56:21 by remanuel          #+#    #+#             */
/*   Updated: 2023/05/11 22:03:49 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <math.h>


void	*create_window(int width, int height, char *title)
{	
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, title);
	(void)mlx_win;
	mlx_loop(mlx);
	return (mlx_win);
}

void	*create_new_img(int width, int height)
{
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, width, height);
	return (img);
}

void	put_pixel(s_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int generate_color(int index)
{
    // Use a color generation function that takes an index and returns a color value
    // For example:
    int r = (index * 37) % 256;
    int g = (index * 73) % 256;
    int b = (index * 131) % 256;
    return (r << 16) | (g << 8) | b;
}

void draw_rotated_square(s_img *data, int x, int y, int size, float angle)
{
    int i;
    int j;
    float cos_a = cos(angle);
    float sin_a = sin(angle);
    int radius = size / 2;
    int color_index1 = 3;
    int color_index2 = 0;

    for (i = x - radius; i < x + radius; i++)
    {
        for (j = y - radius; j < y + radius; j++)
        {
            int dx = i - x;
            int dy = j - y;
            int rotated_x = dx * cos_a - dy * sin_a;
            int rotated_y = dx * sin_a + dy * cos_a;
            if (rotated_x > -radius && rotated_x < radius && rotated_y > -radius && rotated_y < radius)
            {
                if (rotated_x > -radius + 5 && rotated_x < radius - 5 && rotated_y > -radius + 5 && rotated_y < radius - 5)
                {
                    put_pixel(data, i, j, generate_color(color_index1));
                    //color_index1 = (color_index1 + 1);// % MAX_COLOUR_INDEX;
                }
                else
                {
                    put_pixel(data, i, j, generate_color(color_index2));
                    //color_index2 = (color_index2 + 1) % MAX_COLOUR_INDEX;
                }
            }
        }
    }
}

int	main(void)
{
	void *mlx;
	void *mlx_win;
	int	width;
	int	height;
	//int pixel_x;
	//int pixel_y;
	float angle = 0;
	s_img image;
	int rotation_speed;
	
	width = 1000;
	height = 1000;
	rotation_speed = 10000;
	//pixel_x = 0;
	//pixel_y = 0;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Sexo");
	image.img = create_new_img(width, height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	//mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
	//while (pixel_y < height)
	//{
	//	pixel_x = 0;
	//	while (pixel_x < width)
	//	{
	//		put_pixel(&image, pixel_x, pixel_y, 0x00000000);
	//		pixel_x++;
	//	}
	//	pixel_y++;
	//}
    //draw_red_square(&image, 600, 600);
	while(1)
	{
		draw_rotated_square(&image, width / 2, height / 2, 300, angle);
		mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
        //angle = (angle + 3) % 360; // Update angle for next frame
		angle -= 0.01;
		if(rotation_speed > 1)
		{
        usleep(rotation_speed); // Delay for smoother animation
		rotation_speed--;
		}
	}

    //mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
    mlx_loop(mlx);
	//mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
	return (0);
}

