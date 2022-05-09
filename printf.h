/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:27:55 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/09 18:55:26 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLINTF_H
# define PLINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *, ...);
size_t	count_percent(const char *str);
size_t	count_percent_percent(const char *str);
char	printstr(const char *str, char	*s);
char	printstr_condition(const char *str, size_t percent);
int		ft_isspecifier(int c);
char	check_notspecific(const char *str);


int	ft_put_base(int n, int radix);
int ft_put_unchar(int c);
int	ft_put_uint(unsigned int n);
int	ft_put_pointer(void *n);

size_t	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
#endif
