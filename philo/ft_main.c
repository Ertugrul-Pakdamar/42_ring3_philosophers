/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:44:59 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:02:40 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!ft_is_argv_valid(argc, argv))
		ft_exit_prog(NULL, -1);
	data = (t_data *)malloc(sizeof(t_data));
	ft_init_args(data, argv);
	ft_init_philos(data);
	ft_create_threads(data);
	ft_close_threads(data);
	ft_exit_prog(data, 0);
}
