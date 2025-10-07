/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:03:58 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:12:28 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_everyone_ate_enough(t_data *data)
{
	int	i;
	int	eaten;

	if (data->meals_required == -1)
		return (0);
	i = 0;
	while (data->philos[i])
	{
		pthread_mutex_lock(&data->meals_required_mutex);
		eaten = data->philos[i]->meals_eaten;
		pthread_mutex_unlock(&data->meals_required_mutex);
		if (eaten < data->meals_required)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_philo_alive(t_data *data, int i)
{
	long long	last;

	pthread_mutex_lock(&data->time_mutex);
	last = data->philos[i]->last_meal_time;
	pthread_mutex_unlock(&data->time_mutex);
	if (ft_get_time(data) - last >= data->time_to_die)
	{
		pthread_mutex_lock(&data->die_mutex);
		data->someone_died = 1;
		pthread_mutex_unlock(&data->die_mutex);
		ft_print_status(data, data->philos[i], DIED);
		return (0);
	}
	return (1);
}

void	*ft_death_thread(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (data->philos[i])
		{
			if (!ft_check_philo_alive(data, i))
				return (NULL);
			i++;
		}
		if (ft_everyone_ate_enough(data))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}