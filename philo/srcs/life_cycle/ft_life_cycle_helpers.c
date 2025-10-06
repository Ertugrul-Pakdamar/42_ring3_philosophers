/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:20:00 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/06 18:10:03 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_one_philo_cycle(pthread_mutex_t *right, t_data *data, t_philo *philo)
{
	pthread_mutex_lock(right);
	ft_print_status(data, philo, FORK);
	while (!ft_get_die(data))
		usleep(1000);
	pthread_mutex_unlock(right);
	return (0);
}

int	ft_multi_philo_cycle(pthread_mutex_t *right, pthread_mutex_t *left,
		t_data *data, t_philo *philo)
{
	pthread_mutex_t	*primary_fork;
	pthread_mutex_t	*secondary_fork;

	if (philo->id % 2 == 0)
	{
		primary_fork = right;
		secondary_fork = left;
	}
	else
	{
		primary_fork = left;
		secondary_fork = right;
	}
	pthread_mutex_lock(primary_fork);
	ft_print_status(data, philo, FORK);
	if (ft_get_die(data))
		return (pthread_mutex_unlock(primary_fork));
	pthread_mutex_lock(secondary_fork);
	ft_print_status(data, philo, FORK);
	return (1);
}

int	ft_prepare_to_eat(t_data *data, t_philo *philo)
{
	int				idx;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;

	if (ft_get_die(data))
		return (0);
	idx = philo->id - 1;
	right = &data->philos[idx]->right_fork;
	if (idx == 0)
		left = &data->philos[data->philo_count - 1]->right_fork;
	else
		left = &data->philos[idx - 1]->right_fork;
	if (data->philo_count == 1)
	{
		return (ft_one_philo_cycle(right, data, philo));
	}
	return (ft_multi_philo_cycle(right, left, data, philo));
}
