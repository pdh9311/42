#include "philo.h"

int	check_arg(t_info *info, int argc)
{
	if (info->num_of_philo <= 0)
		return (print_error("num_of_philo : argument value error"));
	if (info->time_to_die > INT_MAX)
		return (print_error("time_to_die : argument value error" ));
	if (info->time_to_eat > INT_MAX)
		return (print_error("time_to_eat : argument value error" ));
	if (info->time_to_sleep > INT_MAX)
		return (print_error("time_to_sleep : argument value error" ));
	if (argc == 6 && info->must_eat <= 0)
		return (print_error("must_eat : argument value error"));
	return (0);
}

int	init_fork(t_info *info)
{
	int	i;

	info->fork = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (info->fork == NULL)
		return (print_error("malloc error"));
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (print_error("mutex init error"));
	}
	return (0);
}

int	init_info(t_info *info, int argc, char *argv[])
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->must_eat = atoi(argv[5]);
	}
	else
		info->must_eat = -1;
	if (check_arg(info, argc))
		return (print_error("\tin check_arg function"));
	info->stop = 0;
	info->base_time = 0;
	if (init_fork(info))
		return (print_error("\tin init_fork function"));
	if (pthread_mutex_init(&info->print, NULL))
		return (print_error("mutex init error"));
	return (0);
}

int	init_philo(t_info *info)
{
	int		i;
	t_philo	*philo;

	philo = info->philo;
	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (philo == NULL)
		return (print_error("malloc error"));
	i = -1;
	while (++i < info->num_of_philo)
	{
		philo[i].id = i;
		philo[i].fork_l = i;
		philo[i].fork_r = (i + 1) % info->num_of_philo;
		philo[i].startime_eat = 0;
		philo[i].startime_sleep = 0;
		philo[i].eat_count = 0;
		philo[i].info = info;
		if (pthread_mutex_init(&philo[i].barrier, NULL))
			return (print_error("mutex init error"));
	}
	info->philo = philo;
	return (0);
}
