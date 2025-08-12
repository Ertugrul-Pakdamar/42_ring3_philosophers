/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:13:38 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/12 10:24:26 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_get_die(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->die_mutex);
	res = data->someone_died;
	pthread_mutex_unlock(&data->die_mutex);
	return (res);
}

int	ft_get_meal(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->meals_required_mutex);
	res = data->meals_required;
	pthread_mutex_unlock(&data->meals_required_mutex);
	return (res);
}

long long	ft_get_time(t_data *data)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_close_threads(data);
		ft_exit_prog(data, -1);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
