/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:52 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:56 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** [ leak check in mac]
 *  ...
 *  + system("leaks fdf");
 *  exit(0);
 */
int	key_press(int keycode, t_fdf *data)
{
	int	press;

	press = 1;
	if (keycode == ESC)
	{
		final_free(data);
		system("leaks fdf");
		exit(0);
	}
	iso_plane_key(keycode, data);
	direction_key(keycode, data, press);
	zoom_key(keycode, data, press);
	rotate_key(keycode, data, press);
	z_value_key(keycode, data, press);
	return (0);
}

int	key_release(int keycode, t_fdf *data)
{
	int	release;

	release = 0;
	direction_key(keycode, data, release);
	zoom_key(keycode, data, release);
	rotate_key(keycode, data, release);
	z_value_key(keycode, data, release);
	return (0);
}
