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
	printf("0x: %d\n", n);
	printf("Oh, thats a SIGSEV");
}

int	main(void)
{
	struct sigaction action;
	sigaction(SIGINT, &handler, NULL);
}



