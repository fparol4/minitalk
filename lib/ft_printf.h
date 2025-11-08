/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparola <fparola@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:37:28 by fparola           #+#    #+#             */
/*   Updated: 2025/09/27 20:37:28 by fparola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* REMOVE */
# include <stdio.h>

/* libs */
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

/* ft_handler */
int		ft_handle_int(int value);
int		ft_handle_ptr(size_t address);
int		ft_handle_unsigned(unsigned int value);
int		ft_handle_hex(unsigned int value, int low);

/* ft_string.c */
int		ft_putchar(char c);
int		ft_putstr(char *c, int f);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

/* ft_int.c */
int		ft_signal(int v);
int		ft_abs(int v);

/* ft_calloc */
void	*ft_calloc(size_t nmemb, size_t size);

/* ft_itoa + ft_itoa_unsigned */
char	*ft_itoa(int v, char *base);
char	*ft_itoa_unsigned(size_t v, char *base);

/* ft_printf */
int		ft_printf(const char *format, ...);

#endif
