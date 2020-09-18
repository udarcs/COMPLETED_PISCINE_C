/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <RTFM@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 

Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Точно воспроизведите поведение функции strpbrk (man strpbrk).

Функция должна быть обьявлена следующим образом:

char	*ft_strpbrk(const char *s1, const char *s2);

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		find_char(const char c, const char *str) // это функция ищет букву в str
{
	while (*str) // идем до конца
	{
		if (*str == c)  // с идет от *s1 и он не изменен
			return (1); // если равно возвращаем 1
		++str;
	}
	return (0); // если не равно 1 то переходим на след букву из s1
}

char	*ft_strpbrk(const char *s1, const char *s2) 
{
	while (*s1) // до конца *s1
	{
		if (find_char(*s1, s2) == 1)  // передаем s2 без *
			return ((char *)s1);   // 
		++s1;
	}
	return (0);
}

//--------------------------------------------------------------
// #include <stdio.h>
// #include <string.h>

// int		main(void)
// {
// 	printf("ft: %s; real: %s\n", \
// 		ft_strpbrk("This is a string to search in", "qxd"), \
// 		strpbrk("This is a string to search in", "qxd")
// 		);

// 	printf("ft: %s; real: %s\n", \
// 		ft_strpbrk("This is a string to search in", "sh"), \
// 		strpbrk("This is a string to search in", "sh")
// 		);
// }
