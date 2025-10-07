/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:20:00 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:40:23 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_one_philo_cycle(int idx, t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->philos[idx]->right_fork);
	ft_print_status(data, philo, FORK);
	while (!ft_get_die(data))
		usleep(1000);
	pthread_mutex_unlock(&data->philos[idx]->right_fork);
	return (0);
}

int	ft_multi_philo_cycle(int idx, pthread_mutex_t *left, t_data *data,
		t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data->philos[idx]->right_fork);
		ft_print_status(data, philo, FORK);
		if (ft_get_die(data))
			return (pthread_mutex_unlock(&data->philos[idx]->right_fork));
		pthread_mutex_lock(left);
		ft_print_status(data, philo, FORK);
	}
	else
	{
		usleep(200);
		pthread_mutex_lock(left);
		ft_print_status(data, philo, FORK);
		if (ft_get_die(data))
			return (pthread_mutex_unlock(left));
		pthread_mutex_lock(&data->philos[idx]->right_fork);
		ft_print_status(data, philo, FORK);
	}
	return (1);
}

int	ft_prepare_to_eat(t_data *data, t_philo *philo)
{
	int				idx;
	pthread_mutex_t	*left;

	if (ft_get_die(data))
		return (0);
	idx = philo->id - 1;
	if (data->philo_count == 1)
	{
		return (ft_one_philo_cycle(idx, data, philo));
	}
	if (idx == 0)
		left = &data->philos[data->philo_count - 1]->right_fork;
	else
		left = &data->philos[idx - 1]->right_fork;
	return (ft_multi_philo_cycle(idx, left, data, philo));
}
