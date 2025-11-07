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

char *str_tobuffer(char *str) {
    int size = ft_strlen(str) * 8;
    char *buffer = ft_calloc(size, sizeof(char));
    while (*str)
    {
        int c_int = *str - '0';
        char *c_bin = ft_itoab(c_int, "01");
        c_bin = ft_padstart(c_bin, 8, "0");
        printf("x0: %s\n", c_bin);
        str++;
    }
    return str;
}

int main(int argc, char *argv[]) {
    char *x0 = "message";
    str_tobuffer(x0);
}
