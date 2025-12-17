/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:56:09 by rdeimaos          #+#    #+#             */
/*   Updated: 2025/12/17 12:44:17 by rdeimaos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	pos;

	i = 0;
	num = 0;
	pos = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			pos = -pos;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * pos);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	write_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->philo_check->mutex_print);
	printf("%ld %d %s\n", get_time() - philo->philo_check->start,
			philo->thread_id + 1, msg);
	pthread_mutex_unlock(&philo->philo_check->mutex_print);
}
