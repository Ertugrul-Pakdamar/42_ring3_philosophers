/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:36:47 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:13:22 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_print_status(t_data *data, t_philo *philo, int status)
{
	long long	timestamp;

	pthread_mutex_lock(&data->print_mutex);
	timestamp = ft_get_time(data) - data->start_time;
	if (status == FORK && !ft_get_die(philo->data))
		printf("%lld %d has taken a fork\n", timestamp, philo->id);
	if (status == EATING && !ft_get_die(philo->data))
		printf("%lld %d is eating\n", timestamp, philo->id);
	if (status == SLEEPING && !ft_get_die(philo->data))
		printf("%lld %d is sleeping\n", timestamp, philo->id);
	if (status == THINKING && !ft_get_die(philo->data))
		printf("%lld %d is thinking\n", timestamp, philo->id);
	if (status == DIED)
		printf("%lld %d died\n", timestamp, philo->id);
	pthread_mutex_unlock(&data->print_mutex);
}