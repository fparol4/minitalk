#include <bits/types/sigevent_t.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>

int U_SECOND = 1000 * 1000;
int SIGNALS = 0;

void wm(char *m) { write(1, m, strlen(m)); }

void handler(int signal, siginfo_t *si, void *context) {
    char c = (char) si->si_value.sival_int;
    wm(&c);
}

void set_handler() {
  struct sigaction sa;
  sigemptyset(&sa.sa_mask);
  sa.sa_sigaction = handler;
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &sa, NULL);
}

void fn_showpid() {
  pid_t pid;
  pid = getpid();
  printf("-- PID: %d --\n", pid);
}

void h(int s) { wm("Hi, this is a signal\n"); }

int main(int argc, char *argv[]) {
  fn_showpid();
  set_handler();
  while (1) {
    sleep(1);
    // wm("Waiting...\n");
  }
  return 0;
}
