#include "philo.h"
/**
 * fork_r, fork_l 출력하면서 확인
 */
void	print_status(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->stop)
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	printf("%ld\t", get_time() - philo->info->base_time);
	printf("%d ", philo->id + 1);
	if (status == FORK_R)
		printf("has taken a fork\n");
	else if (status == FORK_L)
		printf("has taken a fork\n");
	else if (status == EATING)
		printf("%sis eating%s\n", C_AQUA, C_NC);
	else if (status == SLEEPING)
		printf("is sleeping\n");
	else if (status == THINKING)
		printf("is thinking\n");
	else if (status == DIED)
		printf("%sdied%s\n", C_RED, C_NC);
	pthread_mutex_unlock(&philo->info->print);
}
