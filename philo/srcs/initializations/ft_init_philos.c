/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:03:42 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/12 13:14:33 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_init_philos(t_data *data)
{
	int	i;
	int	count;

	count = data->philo_count;
	data->philos = (t_philo **)malloc(sizeof(t_philo *) * (count + 1));
	if (!data->philos)
		ft_exit_prog(data, -1);
	(data->philos)[count] = NULL;
	i = 0;
	while (i < count)
	{
		data->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!data->philos[i])
			ft_exit_prog(data, -1);
		data->philos[i]->id = i + 1;
		data->philos[i]->data = data;
		data->philos[i]->last_meal_time = ft_get_time(data);
		data->philos[i]->meals_eaten = 0;
		i++;
	}
}
