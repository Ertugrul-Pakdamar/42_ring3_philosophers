/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlock_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:36:49 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:17:40 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_unlock_forks(int id, t_data *data)
{
	id--;
	if (id == 0)
	{
		pthread_mutex_unlock(&data->philos[id]->right_fork);
		pthread_mutex_unlock(&data->philos[data->philo_count - 1]->right_fork);
	}
	else
	{
		pthread_mutex_unlock(&data->philos[id]->right_fork);
		pthread_mutex_unlock(&data->philos[id - 1]->right_fork);
	}
}
