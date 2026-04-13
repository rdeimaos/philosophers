/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:22:27 by rdeimaos          #+#    #+#             */
/*   Updated: 2025/12/17 12:44:10 by rdeimaos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

typedef pthread_mutex_t t_mutex;

typedef struct s_philo
{
	pthread_t		thread_id;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	int				id;
	long			last_meal;
	t_philo_check	*philo_check;
}	t_philo;

typedef struct s_philo_check
{
	long	time_sleep;
	long	time_eat;
	long	time_die;
	int		num_philo;
	long	start;
	int 	alive;
	t_mutex	mutex_print;
	t_mutex	mutex_alive;
	t_mutex	mutex_meal;
}	t_philo_check;


int	ft_atoi(const char *str);
void	philo_create(t_philo *philo);
void	philo_check_create(t_philo_check *philo_check, char **av);
long	get_time();
void	meal_start();
void	write_msg(t_philo *philo, char *msg);

#endif
