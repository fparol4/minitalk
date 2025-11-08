/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emitter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparola <fabricio.parola@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:44:40 by fparola           #+#    #+#             */
/*   Updated: 2025/11/06 16:44:40 by fparola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

volatile sig_atomic_t g_acksignal = 0;

static void fn_unlock() { g_acksignal = 0; }

void ft_sendsig(int pid, int bit) {
  while (g_acksignal)
    usleep(100);
  if (bit)
    kill(pid, SIGUSR2);
  else
    kill(pid, SIGUSR1);
  usleep(100);
}

int main(int argc, char *argv[]) {
  signal(SIGUSR1, fn_unlock);
  int pid = ft_atoi(argv[1]);
  char *message = argv[2];
  char **m_bits = ft_str_tobuffer(message);
  // for (int i = 0; i < ft_strlen(message); i++)
  //   for (int j = 0; j < BYTE_SIZE; j++)
  //     ft_sendsig(pid, m_bits[i][j] - '0');
}
