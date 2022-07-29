/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:59:44 by oalaoui-          #+#    #+#             */
/*   Updated: 2022/05/24 15:59:46 by oalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_arg_num(t_arg *arg, int argc, char **argv)
{
	if (!is_num(argv))
		return (1);
	arg->num_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->num_of_must_eat = ft_atoi(argv[5]);
	else
		arg->num_of_must_eat = -1;
	if (arg->num_of_philo <= 0 || arg->time_to_die <= 0 || \
		arg->time_to_eat <= 0 || arg->time_to_sleep <= 0 || \
		arg->num_of_must_eat == 0)
		return (1);
	arg->num_of_end = 0;
	arg->end = 0;
	return (0);
}

int	malloc_arg(t_arg *arg)
{
	arg->philo = malloc(sizeof(t_philo) * arg->num_of_philo);
	if (!arg->philo)
		return (1);
	arg->forks_mutex = malloc(sizeof(pthread_mutex_t) * arg->num_of_philo);
	if (!arg->forks_mutex)
	{
		free(arg->philo);
		return (1);
	}
	return (0);
}

int	get_philo(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		arg->philo[i].id = i;
		arg->philo[i].eat_cnt = 0;
		arg->philo[i].last_ate = 0;
		arg->philo[i].is_dead = 0;
		arg->philo[i].arg = arg;
		arg->philo[i].left_fork = i;
		arg->philo[i].right_fork = (i + 1) % arg->num_of_philo;
		i++;
	}
	return (0);
}

int	get_fork(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_mutex_init(&arg->forks_mutex[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&arg->print_mutex, NULL) != 0)
		return (1);
	return (0);
}
