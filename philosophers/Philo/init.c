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



void	thread_innit(t_philo *philo)
{
	int	num;
	int	i;

	num = philo[0].philo_check->num_philo;
	i = 0;
	while (i < num)
	{
		if(pthread_create(&philo[i].thread_id, NULL,
			 meal_start, &philo[i]) != 0)
		{
			printf("Error creating thread\n");
			return ;
		}
		i++;
	}
}
