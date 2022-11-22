#ifndef PHILO_H
# define PHILO_H

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

# define FORK_R		1
# define FORK_L		2
# define EATING		3
# define SLEEPING	4
# define THINKING	5
# define DIED		6

/* color */
# define C_NC		"\033[0m"
# define C_BLOCK	"\033[30m"
# define C_RED		"\033[31m"
# define C_GREEN	"\033[32m"
# define C_YELLOW	"\033[33m"
# define C_BLUE		"\033[34m"
# define C_PURPLE	"\033[35m"
# define C_AQUA		"\033[36m"

/**
 * stdio.h		: printf
 * string.h		: memset
 * sys/time.h	: gettimeofday
 * unistd.h		: write, usleep
 * stdlib.h		: malloc, free
 * pthread.h
 * : pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
 * 	 pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
 */
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_info
{
	int				num_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eat;
	int				stop;
	size_t			base_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	struct s_philo	*philo;
}	t_info;

typedef struct s_philo
{
	pthread_t		monitor;
	pthread_mutex_t	barrier;
	pthread_t		thread;
	int				id;
	int				fork_l;
	int				fork_r;
	size_t			startime_eat;
	size_t			startime_sleep;
	int				eat_count;
	struct s_info	*info;
}	t_philo;

int		check_arg(t_info *info, int argc);
int		init_fork(t_info *info);
int		init_info(t_info *info, int argc, char *argv[]);
int		init_philo(t_info *info);

void	*monitor(void *param);
int		check_eat_count(t_philo *philo);
void	*routine(void *param);
int		create_thread(t_info *info);

void	waiting(t_info *info, size_t start_time, size_t for_time);
void	pickup(t_philo *philo);
void	putdown(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping_thinking(t_philo *philo);

void	print_status(t_philo *philo, int status);

int		ft_atoi(const char *str);
size_t	get_time(void);
int		print_error(char *error_str);
void	free_all(t_info *info);

#endif
