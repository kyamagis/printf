/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:27:55 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/12 11:27:51 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int			ft_printf(const char *format, ...);
int			ft_put_ten(int n, char *base, int digcount);
int			ft_put_hexa(int n, char *base, int digcount);
int			ft_put_pointer(void *n, char *base, int digcount);
int			ft_put_uint(unsigned int n, char *base, int	digcount);
int			ft_put_unchar(int c);
long long	ft_putstr(char *s, long long size);
size_t		ft_strlen(const char *s);
int			ft_count_ten(int n, int digcount);
int			ft_count_hexa(int n, int digcount);
int			ft_count_pointer(void *n, int digcount);
int			ft_count_uint(unsigned int n, int	digcount);
#endif
