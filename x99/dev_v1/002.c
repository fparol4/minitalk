/*
	Set a handler into a signal
	signals:
		- 
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int n)
{
	write(1, "HI", 2);
}

int	main(void)
{
	signal(SIGINT, handler);
	while (1)
	{
		printf("maybe...\n");
		sleep(1);
	}
}

