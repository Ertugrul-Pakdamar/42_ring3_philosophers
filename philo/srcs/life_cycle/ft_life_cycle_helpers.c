/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:20:00 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/12 18:20:00 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_take_forks(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_lock_left_fork(philo->id, data, 1);
	else
	{
		usleep(1000);
		ft_lock_right_fork(philo->id, data, 1);
	}
}

int	ft_prepare_to_eat(t_data *data, t_philo *philo)
{
	if (ft_get_die(data))
		return (0);
	if (data->philo_count == 1)
	{
		ft_lock_right_fork(philo->id, data, 0);
		while (!ft_get_die(data))
			usleep(1000);
		return (0);
	}
	ft_take_forks(data, philo);
	return (1);
}

void	ft_update_meal_start(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->time_mutex);
	philo->last_meal_time = ft_get_time(data);
	pthread_mutex_unlock(&data->time_mutex);
}

void	ft_after_eat(t_data *data, t_philo *philo)
{
	ft_usleep(data->time_to_eat, data);
	ft_unlock_forks(philo->id, data);
	pthread_mutex_lock(&data->meals_required_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meals_required_mutex);
}

void	ft_sleep_and_think(t_data *data, t_philo *philo)
{
	if (ft_get_die(data))
		return ;
	ft_print_status(data, philo, SLEEPING);
	ft_usleep(data->time_to_sleep, data);
	ft_print_status(data, philo, THINKING);
}
