/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:27:55 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/07 18:42:01 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TEN_BASE_STR "0123456789"
# define S_HEX_BASE_STR "0123456789abcdef"
# define L_HEX_BASE_STR "0123456789ABCDEF"
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_put_ten(int n);
int		ft_put_hexa(unsigned int n, char *base);
int		ft_put_pointer(void *n, ssize_t digcount);
int		ft_put_uint(unsigned int n);
size_t	ft_strlen(const char *s);
#endif
