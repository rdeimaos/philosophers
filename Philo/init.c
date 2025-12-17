/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:57:14 by rdeimaos          #+#    #+#             */
/*   Updated: 2025/12/17 12:53:11 by rdeimaos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	thread_innit(char **av, t_philo *philo)
{
	int	num;
	int	i;

	num = ft_atoi(av[1]);
	i = 0;
	philo -> philo_check -> start = get_time();
	while (i <= num)
	{
		pthread_create(&philo[i].thread_id, NULL, &meal_start, NULL);
	}

}
