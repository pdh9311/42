#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// system("./philo 1 800 200 200");
	// system("./philo 5 800 200 200");
	// system("./philo 5 800 200 200 7");
	system("./philo 5 800 200 200 7 > file");
	// system("./philo 4 410 200 200");
	// system("./philo 3 310 200 100");

	/** 정상 */
	// system("./philo 2 210 100 100");
	// system("./philo 4 310 100 200");
	// system("./philo 4 410 200 200");
	// system("./philo 5 610 200 200");
	// system("./philo 5 410 100 300");
	// system("./philo 199 610 200 200");

	/** 인자 에러 처리 */
	// system("./philo 0 210 100 100");
	// system("./philo 4 -450 150 100");
	// system("./philo 4 450 -150 100");
	// system("./philo 4 450 150 -100");
	// system("./philo 4 310 100 200 0");
	// system("./philo 4 310 100 200 -5");

	/** 포크가 하나 밖에 없어서 죽는 경우 */
	// system("./philo 1 210 100 100");			// die

	/** 포크를 기다리다가 못 먹어서 죽는 경우 */
	// system("./philo 4 310 200 100");			// 2,4 die
	// system("./philo 5 410 200 200");			// 2,4 die

	/** 2,4 먹는 시간이 길어 져서 죽는 경우 */
	// system("./philo 4 410 420 200");			// 1,3 die
	// system("./philo 5 410 420 200");			// 1,3,5 die

	/** 잠자다가 죽는 경우*/
	// system("./philo 4 310 100 300");			// 2,4 die
	// system("./philo 5 410 100 400");			// 2,4 die

	/** 프로세스나 스레드 한계로 인한 die */
	// system("./philo_bonus 198 410 100 200");

	/** 아마도 많은 스레드의 할당으로 context switching이 일어나 시간지연이 발생 하면서 죽는 경우 */
	// system("./philo 198 310 200 100");		// die
	// system("./philo 198 310 100 200");		// die
	// system("./philo 198 410 200 200");		// die
	// system("./philo 199 410 100 300");		// die

	/** must eat */
	// system("./philo 2 210 100 100 5");
	// system("./philo 4 310 100 200 5");
	// system("./philo 4 410 200 200 5");
	// system("./philo 5 610 200 200 5");
	// system("./philo 5 410 100 300 5");
	// system("./philo 198 410 100 200 5");
	// system("./philo 199 610 200 200 5");

	// system("./philo 4 310 200 100 5");		// die

	// system("./philo 4 30 10 10");
	// system("./philo 5 40 10 10");
	// system("./philo 4 50 20 20");
	// system("./philo 5 70 20 20");
	// system("./philo 4 90 40 40");
	// system("./philo 4 110 50 50");
}
