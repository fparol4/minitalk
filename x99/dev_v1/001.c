/*
	1. Write a function that uses `sleep` and `getpid`
	2. Write a function that receives a signal
*/

#include <unistd.h>
#include <stdio.h>
#include "000.c"

void	T_SLEEP_01() {
	w_str("helloworld");
	usleep(1000 * 1000);
	w_str("world");
}

void	T_PID_01() {
	int pid = getpid();
	printf("PID: %d\n", pid);
}

int	main(void)
{
	// T_SLEEP_01();
	int pid = getpid();

	while (1)
	{
		usleep(100);
	}
}
