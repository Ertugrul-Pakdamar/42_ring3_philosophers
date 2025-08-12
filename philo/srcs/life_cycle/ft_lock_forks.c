/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:36:57 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/12 11:52:01 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_lock_right_fork(int id, t_data *data, int type)
{
	pthread_mutex_t	*rightfork;

	id--;
	if (id == data->philo_count - 1)
	{
		pthread_mutex_lock(&data->philos[0]->right_fork);
		rightfork = &data->philos[0]->right_fork;
	}
	else
	{
		pthread_mutex_lock(&data->philos[id]->right_fork);
		rightfork = &data->philos[id]->right_fork;
	}
	ft_print_status(data, data->philos[id], FORK);
	if (type == 1 && data->philo_count != 1)
		ft_lock_left_fork(data->philos[id]->id, data, 0);
	else
		ft_usleep(data->time_to_eat, data);
}

void	ft_lock_left_fork(int id, t_data *data, int type)
{
	pthread_mutex_t	*leftfork;

	id--;
	if (id == 0)
	{
		pthread_mutex_lock(&data->philos[data->philo_count - 1]->right_fork);
		leftfork = &data->philos[data->philo_count - 1]->right_fork;
	}
	else
	{
		pthread_mutex_lock(&data->philos[data->philo_count - 1]->right_fork);
		leftfork = &data->philos[id - 1]->right_fork;
	}
	ft_print_status(data, data->philos[id], FORK);
	if (type == 1 && data->philo_count != 1)
		ft_lock_right_fork(data->philos[id]->id, data, 0);
	else
		ft_usleep(data->time_to_eat, data);
}
