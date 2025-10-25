#include <bits/types/sigevent_t.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>

int U_SECOND = 1000 * 1000;
int SIGNALS = 0;

void handler(int signal, siginfo_t *siginfo, void *context) {
  printf("RECEIVED");
}

void set_handler() {
  struct sigaction sa;
  sigemptyset(&sa.sa_mask); // clear memory
  sa.sa_sigaction = handler;
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &sa, NULL);
}

void wm(char *m) { write(1, m, strlen(m)); }

void h(int s) { wm("Hi, this is a signal\n"); }

int main(int argc, char *argv[]) {
  // set_handler();
  pid_t pid = getpid();
  signal(SIGUSR1, h);
  printf("D0:%d\n", pid);
  while (1) {
    // kill(pid, SIGUSR1);
    wm("Waiting...\n");
    sleep(1);
  }
  return 0;
}
