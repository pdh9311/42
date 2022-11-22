/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:06:05 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:06:06 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**************************************************************
 * 	(case 1)	| red orange yellow green blue indigo purple  *
 * 		z0   z1	|											  *
 * 	z0|	10 → 0	|											  *
 * 		↓		|											  *
 * 	z1|	0		|											  *
 * ************************************************************
 * 	(case 2)	| purple indigo blue green yellow orange red  *
		0	z0	|											  *
		↓		|											  *
	0 → 10	z1	|											  *
	z0	z1		|											  *
 * ************************************************************/
static int	color_cast1(t_bresenham *b)
{
	int		color;
	double	curr_l;

	curr_l = sqrt(pow((b->x1 - b->x), 2) + pow((b->y1 - b->y), 2));
	if (curr_l > (b->l * 6 / 7))
	{
		color = RED;
	}
	else if (curr_l > (b->l * 5 / 7))
		color = ORANGE;
	else if (curr_l > (b->l * 4 / 7))
		color = YELLOW;
	else if (curr_l > (b->l * 3 / 7))
		color = GREEN;
	else if (curr_l > (b->l * 2 / 7))
		color = BLUE;
	else if (curr_l > (b->l * 1 / 7))
		color = INDIGO;
	else
		color = PURPLE;
	return (color);
}

static int	color_cast2(t_bresenham *b)
{
	int		color;
	double	curr_l;

	curr_l = sqrt(pow((b->x1 - b->x), 2) + pow((b->y1 - b->y), 2));
	if (curr_l > (b->l * 6 / 7))
		color = PURPLE;
	else if (curr_l > (b->l * 5 / 7))
		color = INDIGO;
	else if (curr_l > (b->l * 4 / 7))
		color = BLUE;
	else if (curr_l > (b->l * 3 / 7))
		color = GREEN;
	else if (curr_l > (b->l * 2 / 7))
		color = YELLOW;
	else if (curr_l > (b->l * 1 / 7))
		color = ORANGE;
	else
		color = RED;
	return (color);
}

void	set_color(t_bresenham *b, t_fdf *data)
{
	if (b->z == 0 && b->z1 == 0)
		data->color = PURPLE;
	else if (b->z != 0 && b->z1 != 0)
		data->color = RED;
	else if (b->z > 0 && b->z1 == 0)
		data->color = color_cast1(b);
	else
		data->color = color_cast2(b);
}
