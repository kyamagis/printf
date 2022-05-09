/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:01:46 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/09 20:27:21 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// int ft_printf(const char *str, ...)
// {

// }

 
int main(void)
{
	printf("1 + 2 + 3 = %d\n", vlaadd(3, 1, 2, 4));
	printf("1 + 2 + 3 + 4 = %d\n", vlaadd(4, 1, 2, 3, 4));
	printf("1 + 2 + 3 + 4 + 5 = %d\n", vlaadd(5, 1, 2, 3, 4, 5));
	printf("1 + 2 + 3 + 4 + 5 + 6 = %d\n", vlaadd(6, 1, 2, 3, 4, 5, 6));
	printf("1 + 2 + 3 + 4q + 5 + 6 + 7 = %d\n", vlaadd(7, 1, 2, 3, 4, 5, 6, 7));
	//printf("");
	printf("d,%d\n", +INT_MAX);
	printf("d,%d\n", -9);
	printf("i,%i\n", +INT_MAX);
	printf("i,%i\n", -9);
	printf("u,%u\n", -9);
	printf("x,%x\n", INT_MIN);
	printf("x,%x\n", INT_MIN + 10);
	printf("x,%x\n", -1);
	printf("x,%x\n", -2147483647);
	printf("X,%X\n", INT_MAX);
	printf("\n\n");
	int i=100;
	printf("%d\n",i);
	int *pointer = &i;
	printf("%p\n",i);
	printf("%p",pointer);

	printf("ft_printf(return): %d\n", ft_printf("ft_printf(output): hello, %c, %s, %p, %d, %i, %u, %x, %X, %%%%\n", 'a', s, a, -2147483647, 2147483647, 2147483647, 2147483647, 2147483647));
	printf("printf(return)   : %d\n", printf("printf(output)   : hello, %c, %s, %p, %d, %i, %u, %x, %X, %%%%\n", 'a', s, a, -2147483647, 2147483647, 2147483647, 2147483647, 2147483647));
	return 0;
}

int vlaadd(int num, ...)
{
	int i, sum;
	va_list va_ptr;

	va_start(va_ptr, num);

	for (i = sum = 0; i < num; i++) 
	{
		sum += va_arg(va_ptr, int);
	}

	va_end(va_ptr);
	return sum;
}


int	ft_isspecifier(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' \
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

size_t	writestr(const char *str, va_list pmts)
{
	size_t	i;
	size_t	strlen;

	strlen = 0;
	va_start(pmts, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_isspecifier(str[i]) == 1)
			{
				strlen += ft_write_condition(str[i], pmts);
				i++;
			}
		}
		ft_putchar_fd(str[i], 1);
		strlen++;
		i++;
	}
	va_end (pmts);
	return (strlen);
}

size_t	ft_write_condition(int c, va_list pmts)
{
	if (c == 'c')
		return (ft_put_unchar(va_arg(pmts, int))); //unsigen char に変換
	if (c == 's')
		return (ft_putstr_fd(va_arg(pmts, char *), 1));//unsigen char に変換
	if (c == 'p')
		return (ft_put_pointer(va_arg(pmts, void *)));// void *ポインタ引数は16進数で出力されます {`％＃x`または`％＃lx`}
	if (c == 'd' || c == 'i')
		return (ft_put_base(va_arg(pmts, int), 10));
	if (c == 'u')
		return (ft_put_uint(va_arg(pmts, int))); // Prints an unsigned decimal (base 10) number.
	if (c == 'x')
		return (ft_put_base(va_arg(pmts, int), 'x'));
	if (c == 'X')
		return (ft_put_base(va_arg(pmts, int), 'X'));
}


