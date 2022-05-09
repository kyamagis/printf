/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:49:49 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/09 20:08:14 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	ft_put_unchar(int c)
{
	unsigned char	unc;

	unc = (unsigned char)c;
	write (1, &c, 1);
	return (1);
}
/*int main(void)
{
	printf("%d\n", printf("%d", 1));
	printf("%d\n", printf("A"));
	printf("%d\n", printf("AB"));
	printf("%d\n", printf("AB%%"));
	printf("%d\n", printf("AB%s", "aiueo"));
	printf("%d\n", printf(""));
	ft_putchar_fd('c', 1);
}*/