/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:35:28 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 10:11:54 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	right_fork;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	int				someone_died;
	long long		start_time;
	t_philo			**philos;
}					t_data;

int					ft_is_argv_valid(int argc, char **argv);
int					ft_custom_atoi(char *str, int *num);
int					ft_isdigit(int c);
void				ft_init_args(t_data *data, char **argv);
void				ft_exit_prog(t_data *data, int exit_code);
void				ft_init_philos(t_data *data);

#endif
