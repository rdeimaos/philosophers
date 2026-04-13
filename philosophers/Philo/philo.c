/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:13:56 by rdeimaos          #+#    #+#             */
/*   Updated: 2025/12/17 15:08:01 by rdeimaos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	av_check(char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

long	get_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	philo_create(t_philo *philo, t_philo_check *philo_check, t_mutex *forks)
{
	int	i;

	i = 0;
	while (i < philo_check->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % philo_check->num_philo];
		philo[i].last_meal = philo_check->start;
		philo[i].philo_check = philo_check;
		i++;
	}
}
t_philo_check	*philo_check_create(char **av)
{
	t_philo_check	*philo_check;

	philo_check = malloc(sizeof(t_philo_check));
	if (!philo_check)
		return ;
	philo_check -> time_eat = ft_atoi(av[3]);
	philo_check -> time_sleep = ft_atoi(av[4]);
	philo_check -> time_die = ft_atoi(av[2]);
	philo_check -> num_philo = ft_atoi(av[1]);
	philo_check -> alive = 1;
	pthread_mutex_init(&philo_check -> mutex_print, NULL);
	pthread_mutex_init(&philo_check -> mutex_alive, NULL);
	pthread_mutex_init(&philo_check -> mutex_meal, NULL);
	return (philo_check);
}

void init_forks(t_mutex *forks, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo *philo;
	t_mutex *forks;
	t_philo_check *philo_check;
	int	num;
	int i;

	if (ac != 5 || !av_check(av))
		return (1);
	num = ft_atoi(av[1]);
	philo_check = philo_check_create(av);
	philo = malloc(sizeof(t_philo) * num);
	forks = malloc(sizeof(t_mutex) * num);
	if(!philo || !forks || !philo_check)
		return (1);
	init_forks(forks, num);
	philo_create(philo, philo_check, forks);
	thread_innit(philo);
	i = 0;
	while (i < num)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	free_all(philo, philo_check, forks);
	return (0);
}
