/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:19:20 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/11 08:17:30 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_philo.h>

int	ft_custom_atoi(char *str, int *num)
{
	int		index;
	long	result;

	result = 0;
	index = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '+')
		index++;
	if (str[index] == '+')
		return (-1);
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = (result * 10) + (str[index] - '0');
		if (result > INT_MAX)
			return (-1);
		index++;
	}
	*num = result;
	return (0);
}
