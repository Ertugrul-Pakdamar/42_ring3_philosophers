/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:25:54 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 10:31:33 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_create(&data->philos[i]->thread, NULL, ft_life_cycle, data);
		i++;
	}
}
