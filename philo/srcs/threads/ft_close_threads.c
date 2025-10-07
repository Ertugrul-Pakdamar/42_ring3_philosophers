/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:25:54 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:13:08 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_close_threads(t_data *data)
{
	int	i;

	pthread_join(data->death_thread, NULL);
	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(data->philos[i]->thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_count - 1)
	{
		pthread_mutex_destroy(&data->philos[i]->right_fork);
		i++;
	}
	pthread_mutex_destroy(&data->die_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->meals_required_mutex);
	pthread_mutex_destroy(&data->time_mutex);
}