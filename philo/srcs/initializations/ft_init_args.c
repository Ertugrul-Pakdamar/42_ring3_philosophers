/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:42:32 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:01:11 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_init_args(t_data *data, char **argv)
{
	ft_custom_atoi(argv[1], &(data->philo_count));
	ft_custom_atoi(argv[2], &(data->time_to_die));
	ft_custom_atoi(argv[3], &(data->time_to_eat));
	ft_custom_atoi(argv[4], &(data->time_to_sleep));
	if (argv[5])
		ft_custom_atoi(argv[5], &(data->meals_required));
	else
		data->meals_required = -1;
	data->someone_died = 0;
	if (!&data->print_mutex || !&data->die_mutex
		|| !&data->meals_required_mutex || !&data->time_mutex)
		ft_exit_prog(data, 1);
}
