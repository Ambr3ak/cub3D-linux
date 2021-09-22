/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:19 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:46:21 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	ray_down(float angle)
{
	return (angle > 0 && angle < PI);
}

int	ray_up(float angle)
{
	return (!ray_down(angle));
}

int	ray_right(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

int	ray_left(float angle)
{
	return (!ray_right(angle));
}
