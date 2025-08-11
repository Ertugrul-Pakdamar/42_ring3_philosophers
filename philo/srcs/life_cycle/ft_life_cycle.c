/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:28:33 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 13:20:20 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_fork_job(t_data *data, t_philo *philo, int *someone_died)
{
	long long	philo_ate;

	philo_ate = ft_get_time(data);
	if (philo->id % 2 == 0 && !(*someone_died))
		ft_lock_left_fork(philo->id, data, 1);
	else if (!(*someone_died))
		ft_lock_right_fork(philo->id, data, 1);
	if (ft_get_time(data) - philo_ate >= data->time_to_die || *someone_died)
	{
		*someone_died = 1;
		ft_print_status(data, philo, DIED);
		ft_unlock_forks(philo->id, data);
		return (-1);
	}
	return (0);
}

void	*ft_life_cycle(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (!data->someone_died)
	{
		ft_fork_job(data, philo, &data->someone_died);
		ft_print_status(data, philo, EATING);
		ft_usleep(data->time_to_eat, data);
		ft_unlock_forks(philo->id, data);
		ft_print_status(data, philo, SLEEPING);
		ft_usleep(data->time_to_sleep, data);
		ft_print_status(data, philo, THINKING);
	}
	return (NULL);
}
