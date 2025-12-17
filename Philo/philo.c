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

void	philo_create(t_philo *philo, char **av)
{
	philo -> sleeping = -1;
	philo -> thinking = -1;
	philo -> alive = 1;
	philo -> last_meal = get_time();
	philo -> philo_check = philo_check_create(philo -> philo_check, av);
}
void	philo_check_create(t_philo_check *philo_check, char **av)
{
	philo_check -> time_eat = ft_atoi(av[3]);
	philo_check -> time_sleep = ft_atoi(av[4]);
	philo_check -> time_die = ft_atoi(av[2]);
	philo_check -> num_philo = ft_atoi(av[1]);
}

int	main(int ac, char **av)
{
	t_philo philo;

	if (ac == 5)
	{
		if (av_check(av))
		{
			philo_create(&philo, av);
		}
	}
}
