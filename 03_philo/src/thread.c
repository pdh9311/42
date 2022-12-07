#include "philo.h"

/** (usleep을 준 이유)
 * 스레드는 sleep 또는 usleep을 걸어 작업을 일정시간 정지 시켜주지 않는다면,
 * 반복문은 마이크로 초 단위로 반복하면서 실행하게 되는데,
 * 너무 빠른 실행으로 eating 함수에서 startime_eat이 아직 저장되지 않았는데
 * monitor 스레드에서는 이전 startime_eat으로 판단하는 일이 있을 수 있으므로
 * 약간의 지연시간을 걸어줍니다.
 */
void	*monitor(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!philo->info->stop)
	{
		pthread_mutex_lock(&philo->barrier);
		if (get_time() >= philo->startime_eat + philo->info->time_to_die)
		{
			print_status(philo, DIED);
			philo->info->stop = 1;
			pthread_mutex_unlock(&philo->barrier);
			break ;
		}
		pthread_mutex_unlock(&philo->barrier);
		usleep(100);
	}
	return (NULL);
}

int	check_eat_count(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->num_of_philo)
	{
		if (philo->info->philo[i].eat_count < philo->info->must_eat)
			return (0);
	}
	philo->info->stop = 1;
	return (1);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = param;
	if (philo->id % 2 == 0 && philo->info->num_of_philo != 1)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->stop)
	{
		eating(philo);
		if (philo->info->must_eat != -1 && check_eat_count(philo))
			break ;
		if (philo->info->stop)
			break ;
		sleeping_thinking(philo);
		if (philo->info->stop)
			break ;
	}
	return (NULL);
}

int	create_thread(t_info *info)
{
	int		i;
	t_philo	*philo;

	info->base_time = get_time();
	philo = info->philo;
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philo[i].startime_eat = get_time();
		if (pthread_create(&philo[i].thread, NULL, routine, (void *)&philo[i]) \
		|| pthread_create(&philo[i].monitor, NULL, monitor, (void *)&philo[i]))
			return (print_error("thread create error"));
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_join(philo[i].thread, NULL) || \
			pthread_join(philo[i].monitor, NULL))
			return (print_error("thread join error"));
	}
	return (0);
}
