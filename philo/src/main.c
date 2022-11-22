#include "philo.h"

/**
 * ./philo [num_of_philo] [time_to_die] [time_to_eat] [time_to_sleep] [must_eat]
 */
int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (print_error("argument count error"));
	memset(&info, 0, sizeof(t_info));
	if (init_info(&info, argc, argv))
		return (print_error("\tin init_info function"));
	if (init_philo(&info))
		return (print_error("\tin init_philo function"));
	if (create_thread(&info))
	{
		free_all(&info);
		return (print_error("\tin create_thread function"));
	}
	free_all(&info);
	return (0);
}
