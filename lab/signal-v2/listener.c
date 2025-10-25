#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int PID = 1665263;
    // kill(1640236, SIGUSR1);
    union sigval sv;
    char *m = strdup("OPQRSTUV");
    for (int i = 0; i <= strlen(m); ++i)
    {
        sv.sival_int = 0;
        if (i < strlen(m))
            sv.sival_int = m[i];
        sigqueue(PID, SIGUSR1, sv);
        usleep(1000);
    }
    free(m);
    printf("END\n");
}
