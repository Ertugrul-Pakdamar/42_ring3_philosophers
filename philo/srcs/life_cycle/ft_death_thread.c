/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:03:58 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/12 13:15:27 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_death_thread(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (data->philos[i])
		{
			if (ft_get_time(data)
				- data->philos[i]->last_meal_time >= data->time_to_die)
			{
				data->someone_died = 1;
				ft_print_status(data, data->philos[i], DIED);
				return (NULL);
			}
			i++;
		}
		ft_usleep(200, data);
	}
	return (NULL);
}
