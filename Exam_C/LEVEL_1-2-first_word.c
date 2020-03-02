/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <jaleman@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:35:32 by exam              #+#    #+#             */
/*   Updated: 2016/09/01 18:14:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************

Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.
Напишите программу, которая принимает строку и отображает ее первое слово, за 
которым следует новая строка.

A word is a section of string delimited by spaces/tabs or by the start/end of the string.
Слово - это раздел строки, разделенный пробелами / табуляцией или началом / концом строки.

If the number of parameters is not 1, or if there are no words, simply display a newline.
Если количество параметров не равно 1 или нет слов, просто отобразите новую строку.

Examples:
Примеры:


$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



#include <unistd.h>

/* Функция для определения символов конца слова */
int		ft_isspace(int i)				/* принимаем символ для анализа */
{
	if (i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ')	/* если символ такой как в суловии */
		return (1);														/* то вернуть 1 */
	return (0);															/* в обратном случае вернуть 0 */
}

/* Функция печати первого слова из строки */
void	ft_first_word(char *str)
{
	int		i;

	i = 0;
	while (ft_isspace((str[i])))				/* если в этой чейке находятся только символов конца слова*/
		i++;									/* то идем к след ячейке и так пока не дойдем до конца строки */
	while (!ft_isspace(str[i]) && str[i])		/* если в этой чейке не находится символов конца слова или символа конца массива*/
	{
		write(1, &str[i], 1);					/* то печатаем этот символ и переходим к след ячейке */
		i++;
	}
}


int		main(int argc, char *argv[])		/* здесь принимаем количество строк в массиве и сам массив со строками */
{
	if (argc == 2)							/* Проверяем есть ли кроме имени программы в аргументах еще и нужная нам строка */
	{
		ft_first_word(argv[1]);				/* печатаем первое слово этой строки */
	}
	write(1, "\n", 1);						/* Печатаем символ перехода на новую строку */
	return (0);								/* Завершаем программу */
}




/* ************************************************************************** */
/* ****************************_OR_THAT:)_*********************************** */
/* ************************************************************************** */




#include <unistd.h>

/* Функция для определения символов конца слова */
int		ft_isspace(int i)				/* принимаем символ для анализа */
{
	if (i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ')	/* если символ такой как в суловии */
		return (1);														/* то вернуть 1 */
	return (0);															/* в обратном случае вернуть 0 */
}

int		main(int argc, char *argv[])		/* здесь принимаем количество строк в массиве и сам массив со строками */
{
	int		i;								/* для начала обьявим переменную для счетчика */

	i = 0;									/* Инициализируем счетчик нулем чтобы начать с нулевой ячейки массива */
	if (argc == 2)							/* Проверяем есть ли кроме имени программы в аргументах еще и нужная нам строка */
	{
		while (ft_isspace((argv[1][i])))				/* если в этой чейке находятся только символов конца слова*/
				i++;									/* то идем к след ячейке и так пока не дойдем до конца строки */
		while (!ft_isspace(argv[1][i]) && argv[1][i])	/* если в этой чейке не находится символов конца слова или символа конца массива*/
		{
			write(1, &argv[1][i], 1);					/* то печатаем этот символ и переходим к след ячейке */
			i++;
		}
	}
	write(1, "\n", 1);						/* Печатаем символ перехода на новую строку */
	return (0);								/* Завершаем программу */
}