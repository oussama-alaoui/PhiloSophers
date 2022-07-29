/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:00:23 by oalaoui-          #+#    #+#             */
/*   Updated: 2022/05/24 16:00:25 by oalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(char *msg)
{
	printf("Probleme: %s\n", msg);
	return (1);
}

int	ft_atoi(const char *str)
{
	long		nbr;
	long		sign;
	size_t		i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
	}
	return (nbr * sign);
}

int	is_num(char **argv)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	get_time(void)
{
	long long		ret;
	struct timeval	time;

	ret = 0;
	if (gettimeofday(&time, NULL) == -1)
		error_msg("gettimeofday fail");
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	print_philo(t_philo *philo, t_arg *arg, char *msg)
{
	if (arg->end)
		return ;
	pthread_mutex_lock(&arg->print_mutex);
	printf("%lld\t", get_time() - philo->arg->start_time);
	printf("%d\t", philo->id + 1);
	printf("%s\t\n", msg);
	pthread_mutex_unlock(&arg->print_mutex);
}
