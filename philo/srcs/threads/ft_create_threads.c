/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:25:54 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 10:58:00 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = ft_get_time(data);
	while (i < data->philo_count)
	{
		pthread_create(&data->philos[i]->thread, NULL, ft_life_cycle,
				data->philos[i]);
		i++;
	}
}
