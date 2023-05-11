/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:02:17 by remanuel          #+#    #+#             */
/*   Updated: 2023/05/11 21:34:24 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef MAX_COLOUR_INDEX
#define MAX_COLOUR_INDEX 1000
#endif

#include "../minilibx_linux/mlx.h"
#include "../minilibx_linux/mlx_int.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				s_img;

void	*create_window(int width, int height, char *win_name);
void	*create_new_img(int width, int height);

#endif