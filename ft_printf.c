/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:01:46 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/01 18:44:55 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_condition(char c, va_list pmts, ssize_t	len)
{
	ssize_t	size;

	size = 0;
	if (c == 'c')
		size = ft_put_unchar(va_arg(pmts, int));
	if (c == 's')
		size = ft_putstr(va_arg(pmts, char *), len);
	if (c == 'p')
		size = ft_put_pointer(va_arg(pmts, void *), 1);
	if (c == 'd' || c == 'i')
		size = ft_put_ten(va_arg(pmts, int), 1);
	if (c == 'u')
		size = ft_put_uint(va_arg(pmts, unsigned int), 1);
	if (c == 'x')
		size = ft_put_hexa(va_arg(pmts, unsigned int), S_HEX_BASE_STR, 1);
	if (c == 'X')
		size = ft_put_hexa(va_arg(pmts, unsigned int), L_HEX_BASE_STR, 1);
	if (c == '%')
	{
		write(1, "%", 1);
		size = 1;
	}
	if (INT_MAX <= len + size || size == -1)
		return (-1);
	return (len + size);
}

static int	ft_writestr(const char *format, va_list pmts)
{
	size_t	i;
	ssize_t	len;

	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len = ft_write_condition(format[i + 1], pmts, len);
			if (len == -1)
				return (-1);
			i++;
		}
		else
		{
			len++;
			if (INT_MAX <= len)
				return (-1);
			write(1, &format[i], 1);
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	pmts;
	int		len;

	if (format == NULL)
		return (0);
	va_start(pmts, format);
	len = ft_writestr(format, pmts);
	va_end(pmts);
	if (len == -1)
		return (-1);
	return (len);
}
