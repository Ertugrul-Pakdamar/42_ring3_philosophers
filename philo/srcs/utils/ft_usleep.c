/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:04:15 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:02:33 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_usleep(size_t ms, t_data *data)
{
	long long	start;
	long long	now;

	start = (long long)ft_get_time(data);
	while (!ft_get_die(data))
	{
		now = (long long)ft_get_time(data);
		if (now - start >= (long long)ms)
			break ;
		usleep(100);
	}
}
