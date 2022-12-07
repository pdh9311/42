#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

/**
 * tv_sec : seconds
 * tv_usec : microseconds
 * [ transformation in milliseconds ]
 * → (tv_sec * 1000) ms
 * → (tv_usec / 1000) ms
 */
size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	print_error(char *error_str)
{
	printf("%s\n", error_str);
	return (1);
}

void	free_all(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		pthread_mutex_destroy(&info->fork[i]);
		pthread_mutex_destroy(&info->philo[i].barrier);
	}
	pthread_mutex_destroy(&info->print);
	free(info->fork);
	free(info->philo);
}
