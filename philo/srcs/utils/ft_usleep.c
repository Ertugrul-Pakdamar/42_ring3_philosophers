/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:04:15 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 12:06:37 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_usleep(size_t time_in_ms, t_data *data)
{
	int	time;

	time = ft_get_time(data);
	while (ft_get_time(data) - time < time_in_ms)
		usleep(200);
}
