/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:59:58 by oalaoui-          #+#    #+#             */
/*   Updated: 2022/05/24 16:00:00 by oalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_rotine(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_destroy(&(arg->forks_mutex[i]));
		i++;
	}
	pthread_mutex_destroy(&(arg->print_mutex));
	free(arg->forks_mutex);
	free(arg->philo);
}

int	main(int argc, char **argv)
{
	t_arg			arg;

	if (argc > 4 && argc < 7)
	{
		if (get_arg_num(&arg, argc, argv))
			return (error_msg("Invalid arguments"));
		if (malloc_arg(&arg))
			return (error_msg("Malloc error"));
		if (get_philo(&arg) || get_fork(&arg))
			return (error_msg("Initialize error"));
		if (creat_phthread(&arg))
			return (error_msg("Thread error"));
		end_rotine(&arg);
	}
	else
		return (error_msg("Wrong amount of arguments"));
}
