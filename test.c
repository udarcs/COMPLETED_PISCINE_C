

#include <unistd.h>

/* Функция проверки ячеек массива. 
 * Если ячейки массива являются буквами или другими символами(кроме пробелов и табуляций). 
 * то переходим к след ячейке массива и далее, пока символы букв или другие символы не закончаться 
 * а на их месте появятся символы пробела, табуляции или пока массив не закончится */
void	ft_check_word(char *str, int *i)							/* принимаем адрес строки, адрес счетчика */
{
	while (str[*i] != ' ' && str[*i] != '\t' && str[*i])		/* если символы не пробелы и не табуляция то продолжаем цикл */
		(*i)++;													/* И увеличваем счетчик переходя к след ячейке */
}																/* Если нам встетились пробел или табуляция или конец массива
																 * то завершаем цикл и выходим, а функция завершается */



/* Функция проверки ячеек массива. Если ячейки массива являются табуляцией или пробелами  
 * то переходим к след ячейке массива и далее, пока символы табуляции и пробелов не закончатся
 * а на их месте появятся буквы или другие символы, или пока массив не закончится */
void	ft_check_symbol(char *str, int *i)						/* принимаем адрес строки, адрес счетчика */
{
	while ((str[*i] == ' ' || str[*i] == '\t') && str[*i])		/* если символы являются пробелом или табуляцией то продолжаем цикл */
		(*i)++;													/* И увеличваем счетчик переходя к след ячейке */
}																/* Если нам встетились буквы или др сиволы или конец массива
																 * то завершаем цикл и выходим, а функция завершается */


/* Функция печати слова */
void	print_word(char *str, int start, int end)		/* принимаем адрес строки, индекс начала строки, индекс конца строки */
{
	while (str[start] && str[start] != ' ' && str[start] != '\t' && end--) /* если не встретился пробел, табуляция или символ конца строки */
	{
		write(1, &str[start], 1);											/* то печатаем эту ячейку массива */
		start++;															/* увеличиваем переменную чтобы перейти к след ячейке */
	}
}

/* функция печати последнего слова строки */
void 	ft_last_word(char *str)				/* Принимаем адрес строки */
{
	int		i;								/* обьявляем переменную для счетчика */
	int		start;							/* обьявляем переменную для хранения индекса начала слова */
	int		end;							/* обьявляем переменную для хранения индекса конца слова */

	i = 0;									/* инициализируем переменную для счетчика нулем */
	start = 0;								/* инициализируем переменную для хранения индекса начала слова нулем */
	end = 0;								/* инициализируем переменную для хранения индекса конца слова нулем*/
	ft_check_symbol(str, &i);				/* проверяем, являются ли первые символы массива табуляцией или пробелами */
											/* если это так то переходим к след ячейке массива и далее, пока символы табуляции
											 * и пробелов не сменятся другими или пока массив не закончиться */
	while (str[i])							/* Запускаем цикл. который находит индексы на начало и конец каждого слова и
											 * записывает их в соответсвующие переменные 
											 * Если мы дошли до конца массива то запускаем функцию печати слова "print_word"
											 * Так и получится что мы напечатаем последнее слово когда используем последние 
											 * найденные индексы начала и конца слова */
	{
		start = i;							/* Записываем в переменную найденый нами индекс начала слова */
		ft_check_word(str, &i);				/* проверяем когда заканчивается слово */
		end = i;							/* и записываем в переменную найденый нами индекс конца слова */
		ft_check_symbol(str, &i);			/* проверяем есть ли после найденого слова еще символы пробела или табуляции */
		if (!str[i])						/* Если дошли до конца */
			print_word(str, start, end);	/* то печатаем слово на которое указывают последние найденые индексы начала и конца строки */
	}
}

int		main(int argc, char **argv)			/* здесь принимаем количество строк в массиве и сам массив со строками */
{

	if (argc == 2)										/* Проверяем есть ли кроме имени программы в аргументах еще и нужная нам строка */
	{
		ft_last_word(argv[1]);							/* Запускаем функцию печати последнего слова строки */
	}
	write(1, "\n", 1);									/* Печатаем символ перехода на новую строку */
	return (0);											/* Завершаем программу */
}