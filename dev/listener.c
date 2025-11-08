/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparola <fabricio.parola@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:43:05 by fparola           #+#    #+#             */
/*   Updated: 2025/11/05 20:43:05 by fparola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "minitalk.h"
#include <bits/types/siginfo_t.h>
#include <signal.h>
#include <stdbool.h>

void fn_handler(int signal, siginfo_t *si, void *context) {
  static char c_byte;
  static int received_bytes;

  if (signal == SIGUSR1)
    c_byte = (c_byte << 1) | 0;
  if (signal == SIGUSR2)
    c_byte = (c_byte << 1) | 1;
  received_bytes++;
  if (received_bytes % BYTE_SIZE == 0)
    ft_putchar_fd(c_byte, 1);
  if (c_byte == '\0')
      write(1, "\n", 1);
  kill(si->si_pid, SIGUSR1);
}

static void fn_signal() {
  struct sigaction sa;

  // SIG-A
  sigemptyset(&sa.sa_mask);
  sa.sa_sigaction = fn_handler;
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);
}

static int fn_showpid() {
  int pid;

  pid = getpid();
  printf("-- PID: %d --\n", pid);
  return (pid);
}

int main(int argc, char *argv[]) {
  fn_showpid();
  fn_signal();
  while (true)
    usleep(100);
  return 0;
}
