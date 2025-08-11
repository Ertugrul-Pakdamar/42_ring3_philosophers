/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:57:33 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 10:18:10 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_exit_prog(t_data *data, int exit_code)
{
	int	i;

	if (data)
	{
		if (data->philos)
		{
			i = 0;
			while (data->philos[i])
				free(data->philos[i++]);
			free(data->philos);
		}
		free(data);
	}
	if (exit_code == 0)
		printf("Success.");
	if (exit_code == -1)
		printf("Failure.");
	exit(exit_code);
}
