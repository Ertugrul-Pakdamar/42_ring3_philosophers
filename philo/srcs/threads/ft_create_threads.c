/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:25:54 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:13:15 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_create_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->die_mutex, NULL);
	pthread_mutex_init(&data->meals_required_mutex, NULL);
	pthread_mutex_init(&data->time_mutex, NULL);
	pthread_create(&data->death_thread, NULL, ft_death_thread, data);
	data->start_time = ft_get_time(data);
	while (i < data->philo_count)
	{
		philo = data->philos[i];
		pthread_mutex_init(&philo->right_fork, NULL);
		pthread_create(&philo->thread, NULL, ft_life_cycle, philo);
		i++;
	}
}