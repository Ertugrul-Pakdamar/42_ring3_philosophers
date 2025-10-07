/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:45:29 by epakdama          #+#    #+#             */
/*   Updated: 2025/10/07 21:02:38 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_is_args_numable(char **argv)
{
	int	temp;
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_custom_atoi(argv[i], &temp))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_numeric_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_parse_positive_values(char **argv)
{
	int	n;
	int	tdie;
	int	teat;
	int	tsleep;

	if (ft_custom_atoi(argv[1], &n) || ft_custom_atoi(argv[2], &tdie)
		|| ft_custom_atoi(argv[3], &teat) || ft_custom_atoi(argv[4], &tsleep))
		return (0);
	if (n <= 0 || tdie <= 0 || teat <= 0 || tsleep <= 0)
		return (0);
	return (1);
}

int	ft_is_argv_valid(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!ft_is_numeric_args(argv))
		return (0);
	if (!ft_is_args_numable(argv))
		return (0);
	if (argv[1] && argv[2] && argv[3] && argv[4])
		return (ft_parse_positive_values(argv));
	return (1);
}
