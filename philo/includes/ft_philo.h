/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:35:28 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 12:39:55 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DIED 3
# define FORK 4

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	long long			last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		right_fork;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					philo_count;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals_required;
	int					someone_died;
	long long			start_time;
	struct timeval		tv;
	t_philo				**philos;
}						t_data;

int						ft_is_argv_valid(int argc, char **argv);
int						ft_custom_atoi(char *str, int *num);
int						ft_isdigit(int c);
void					ft_init_args(t_data *data, char **argv);
void					ft_exit_prog(t_data *data, int exit_code);
void					ft_init_philos(t_data *data);
void					ft_create_threads(t_data *data);
void					ft_close_threads(t_data *data);
void					*ft_life_cycle(void *arg);
void					ft_lock_left_fork(int id, t_data *data, int type);
void					ft_lock_right_fork(int id, t_data *data, int type);
void					ft_unlock_forks(int id, t_data *data);
void					ft_usleep(size_t time_in_ms, t_data *data);
long long				ft_get_time(t_data *data);
void					ft_print_status(t_data *data, t_philo *philo,
							int status);

#endif
