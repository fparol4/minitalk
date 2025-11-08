/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparola <fabricio.parola@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:35:08 by fparola           #+#    #+#             */
/*   Updated: 2025/08/15 17:53:21 by fparola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define BYTE_SIZE 8

#include "stdio.h"
#include "lib/libft.h"

char **ft_str_tobuffer(char *str);
int     ft_getpid();
void    panic(char *msg);

#endif
