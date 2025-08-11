/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:28:33 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 10:30:59 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_life_cycle(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	(void)data;
	printf("thread started\n");
	return (arg);
}
