#include "philo.h"

void	waiting(t_info *info, size_t startime, size_t for_time)
{
	while (get_time() <= startime + for_time && !info->stop)
		usleep(1000);
}

void	pickup(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
	print_status(philo, FORK_R);
	pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
	print_status(philo, FORK_L);
}

void	putdown(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
}

/** (startime_eat 이 monitor 스레드에서도 사용되는 공유 자원)
 * 스레드는 실행중에 cpu가 자동으로 우선순위를 선택하여
 * a, b 스레드를 왔다갔다 반복하면서 작업을 합니다.
 * 이 상황에서 monitor 스레드에 우선순위가 높아서
 * eating작업을 하지 않는 시간이 생길 수 있는데,
 * 이를 방지하기위해서 mutex_lock을 걸어서
 * monitor 스레드가 eating작업을 마치면 작동할 수 있게 해줍니다.
 * 즉, 먹는것을 끝내는 동안 monitor 스레드가 startime_eat에 접근할 수 없도록 함.
 * 	&공유자원을 하나의 스레드만 접근하는 시간을 주기위해 mutex_lock 한다.
 */
void	eating(t_philo *philo)
{
	if (philo->info->num_of_philo == 1)
	{
		pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
		print_status(philo, FORK_L);
		while (!philo->info->stop)
			usleep(1000);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
	}
	else
	{
		pickup(philo);
		pthread_mutex_lock(&philo->barrier);
		philo->startime_eat = get_time();
		print_status(philo, EATING);
		waiting(philo->info, philo->startime_eat, philo->info->time_to_eat);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->barrier);
		putdown(philo);
	}
}

void	sleeping_thinking(t_philo *philo)
{
	philo->startime_sleep = get_time();
	print_status(philo, SLEEPING);
	waiting(philo->info, philo->startime_sleep, philo->info->time_to_sleep);
	print_status(philo, THINKING);
}
