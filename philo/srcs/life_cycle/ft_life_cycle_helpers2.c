/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle_helpers2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:01:00 by epakdama          #+#    #+#             */
/*   Updated: 2025/09/14 20:05:17 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_update_meal_start(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->time_mutex);
	philo->last_meal_time = ft_get_time(data);
	pthread_mutex_unlock(&data->time_mutex);
}

void	ft_after_eat(t_data *data, t_philo *philo)
{
	int				idx;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;

	ft_usleep(data->time_to_eat, data);
	idx = philo->id - 1;
	right = &data->philos[idx]->right_fork;
	if (idx == 0)
		left = &data->philos[data->philo_count - 1]->right_fork;
	else
		left = &data->philos[idx - 1]->right_fork;
	pthread_mutex_unlock(right);
	pthread_mutex_unlock(left);
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
