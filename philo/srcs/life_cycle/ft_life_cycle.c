/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:28:33 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:12:34 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_update_meal_start(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->time_mutex);
	philo->last_meal_time = ft_get_time(data);
	pthread_mutex_unlock(&data->time_mutex);
}

static void	ft_after_eat(t_data *data, t_philo *philo)
{
	ft_usleep(data->time_to_eat, data);
	ft_unlock_forks(philo->id, data);
	pthread_mutex_lock(&data->meals_required_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meals_required_mutex);
}

static void	ft_sleep_and_think(t_data *data, t_philo *philo)
{
	if (ft_get_die(data))
		return ;
	ft_print_status(data, philo, SLEEPING);
	ft_usleep(data->time_to_sleep, data);
	ft_print_status(data, philo, THINKING);
}

void	*ft_life_cycle(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		my_meal_req;

	philo = (t_philo *)arg;
	data = philo->data;
	my_meal_req = 0;
	while (!ft_get_die(data) && (ft_get_meal(data) == -1
			|| my_meal_req < ft_get_meal(data)))
	{
		if (!ft_prepare_to_eat(data, philo))
			break ;
		ft_print_status(data, philo, EATING);
		ft_update_meal_start(data, philo);
		ft_after_eat(data, philo);
		my_meal_req++;
		if (ft_get_die(data))
			break ;
		ft_sleep_and_think(data, philo);
	}
	return (NULL);
}