/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlock_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:36:49 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/12 11:46:11 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_unlock_forks(int id, t_data *data)
{
	pthread_mutex_t	*rightfork;
	pthread_mutex_t	*leftfork;

    id--;
    rightfork = &data->philos[id]->right_fork;
    if (id == 0)
    {
        leftfork = &data->philos[data->philo_count - 1]->right_fork;
    }
    else
    {
        leftfork = &data->philos[id - 1]->right_fork;
    }
    pthread_mutex_unlock(leftfork);
    pthread_mutex_unlock(rightfork);
}
