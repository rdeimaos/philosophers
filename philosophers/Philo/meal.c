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

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		write_msg(philo, " has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		write_msg(philo, " has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		write_msg(philo, " has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		write_msg(philo, " has taken a fork");
	}
	pthread_mutex_lock(&philo->philo_check->mutex_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->philo_check->mutex_meal);
	write_msg(philo, " is eating");
	ft_sleep(philo->philo_check->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time )
	usleep(100);
}

void	ph_sleep(t_philo *philo)
{
	write_msg(philo, " is sleeping");
	ft_sleep(philo->philo_check->time_sleep);
}

void	think(t_philo *philo)
{
	write_msg(philo, " is thinking");
	ft_sleep(1);
}

void	*meal_start(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	while (is_alive(philo))
	{
		eat(philo);
		ph_sleep(philo);
		think(philo);
	}
	return (NULL);
}
