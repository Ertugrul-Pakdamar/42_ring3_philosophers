/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:28:33 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 12:22:46 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_lock_left_fork(philo->id, philo->data, 1);
	else
	{
		ft_usleep(500, philo->data);
		ft_lock_right_fork(philo->id, philo->data, 1);
	}
	printf("philo %d locked two forks.\n", philo->id);
	ft_usleep(philo->data->time_to_eat, philo->data);
	ft_unlock_forks(philo->id, philo->data);
	printf("philo %d unlocked two forks.\n", philo->id);
	return (NULL);
}
