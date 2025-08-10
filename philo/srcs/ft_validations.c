/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:45:29 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/10 21:30:55 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_is_args_numable(char **argv)
{
	int	temp;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_custom_atoi(argv[i], &temp))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_argv_valid(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		return (0);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '+'
				&& argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	if (!ft_is_args_numable(argv))
		return (0);
	return (1);
}
