/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:06:35 by oalaoui-          #+#    #+#             */
/*   Updated: 2022/05/24 16:06:38 by oalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int					id;
	int					eat_cnt;
	int					left_fork;
	int					right_fork;
	long long			last_ate;
	long long			is_dead;
	pthread_t			philo_tid;
	pthread_t			monitor_tid;
	struct s_arg		*arg;
}t_philo;

typedef struct s_arg
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_must_eat;
	int					num_of_end;
	int					end;
	long long			start_time;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		print_mutex;
	t_philo				*philo;
}t_arg;

int		ft_atoi(const char *str);
int		is_num(char **argv);
int		error_msg(char *msg);
int		get_arg_num(t_arg *arg, int argc, char **argv);
int		malloc_arg(t_arg *arg);
int		get_fork(t_arg *arg);
int		get_philo(t_arg *arg);
int		creat_phthread(t_arg *arg);
void	*routine(void *philo);
void	*check_die(void *philo);
int		get_time(void);
void	print_philo(t_philo *philo, t_arg *arg, char *msg);
void	taking_forks(t_philo *p, t_arg *a);
void	eating(t_philo *p, t_arg *a);
void	sleeping(t_philo *p, t_arg *a);
void	thinking(t_philo *p, t_arg *a);

#endif
