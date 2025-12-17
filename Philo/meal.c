/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:23:11 by rdeimaos          #+#    #+#             */
/*   Updated: 2025/12/17 12:45:25 by rdeimaos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat()
{
	
}

void	ft_sleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time )
	usleep(100);
}

void	sleep(t_philo *philo)
{
	write_msg(&philo, " is sleeping");
	ft_sleep(philo->philo_check->time_sleep);
}

void	think(t_philo *philo)
{
	write_msg(&philo, " is thinking");
	ft_sleep(1);
}

void	*meal_start(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
}
