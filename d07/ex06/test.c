/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>					/* Подкоючаем библиотеку содержащую функцию для вывода символов(write) */
#include <stdlib.h>					/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) функцию для подсчета размера переменной(sizeof) */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

/*#############################################################################*/

void	ft_putstr(char *str)     	/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/*#############################################################################*/

int		ft_ctoi(char c)				/* Функция переводит символ в число и возвращает его. Если символ условиям не соответствует то возвращается (-1)*/
{
	if (c >= '0' && c <= '9')		/* Если символ числа от 0 до 9 */
		return (c - '0');			/* То вычесть из символа числа символ нуля чтобы в остатке осталось только само число в диапазоне до 9 включительно */
	if (c >= 'A' && c <= 'F')		/* Если символ в пределах от 'A' до 'F' то значит перед нами число в пределах от 10 до 16 включительно */
		return (c - 'A' + 10);		/* Чтобы его достать нужно из символа вычесть 'A' и к получившемуся числу прибавить 10.
									 * После завершаем функцию и возвращаем добытое число */
	if (c >= 'a' && c <= 'f')		/* Если символ в пределах от 'a' до 'f' то значит перед нами число в пределах от 10 до 16 включительно */
		return (c - 'a' + 10);		/* Чтобы его достать нужно из символа вычесть 'a' и к получившемуся числу прибавить 10.
									 * После завершаем функцию и возвращаем добытое число */
	return (-1);					/* Если символ не соответсвует ни одному условию то завершаем функцию и возвращаем (-1). */
}

/*#############################################################################*/

int		ft_pow(int nb, int power)	/* Функция возведения в степень */
{
	int	result;						/* обьявляем переменную для хранения добытого результата */

	result = 1;						/* инициализируем ее единицей для начала вычислений результата возведения в степень */
	if(power < 0)					/* Проверяем соответствует ли число в степени условиям */
		return (0);					/* Если не соответствует то завершаем функцию и возвращаем ноль */
	if(power == 0)					/* Проверяем соответствует ли число в степени условиям */
		return (1);					/* Если не соответствует то завершаем функцию и возвращаем ноль */
	while (power--)					/* Запускаем цикл который умножит переменную 'result' на 'nb' столько раз сколько записано в 'power'. Возведет в 'nb' в степень 'power'. */
		result *= nb;				/* Умножая 'result' на 'nb' и сохраняя результат в той же переменной 'result' столько раз сколько записано в 'power'  
									 * мы сможем получить результат возведения в степень 'power' числа 'nb'. */
	return (result);				/* Завершаем функцию и возвращаем результат возведения в степень */
}

/*#############################################################################*/

int		ft_check_base(char *base)	/* Функция проверки массива с нужной на системой счисления на корректность. Она принимает адресс массива 
									 * и возвращает или 0 или размер проверяемого базового типа, если все корректно */
{
	int	i;							/* обьявляем счетчик */
	int	z;							/* обьявляем счетчик */

	i = 0;							/* инициализируем счетчик нулем чтобы начать с начала массива */
	z = 0;							/* инициализируем счетчик нулем чтобы начать с начала массива */
	if (!base || !base[1])			/* если массив пуст */
		return (0);					/* то возвращаем 0 и завершаем цикл и функцию */
	while (base[i])					/* до тех пор пока выбранная ячейка массива не пуста запускаем цикл */
	{
		z = i + 1;					/* сохраняем в переменную z число указывающее на сл ячейку после i */
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z'))) /* проверяем массив, чтобы там были только символы чисел и букв алфавита */
			return (0);				/* если в массиве есть что то не нужное нам то возвращаем 0 и завершаем цикл и функцию */
		while (base[z])				/* запускаем цикл, который проверит все ячеки которые следуют за теми на которые указывает переменная i */
			if (base[i] == base[z++])/* если символ в ячейке на которую указывает i  такой же что и в след ячейке */ 
				return (0);			/* то возвращаем 0 и завершаем цикл и функцию */ /* если нет то продолжаем цикл пробегаясь по остальным ячейка и сравнивая их с i */
		i++;						/* если дошли до сюда значит символ этой ячейки соответсвует условиям и идентичных ему в массиве нет */ /* переходим к проверке сл ячейки */
	}
	return (i);						/* если дошли до сюда, значит массив соответсвует условиям */ /* возвращаем размер базового типа как положительный ответ и завершаем функцию */
}

/*#############################################################################*/

int		ft_get_dec(char *str, char *base)/* Функция преобразующая строку(str) определенного базового типа в десятичное число */
{
	int		num;						/* Обьявляем перменную в которую мы положим преобразованное число */
	int		negative;					/* Обьявляем перменную для хранения информации о том отрицательное это число или положительное */
	int		i;							/* Обьявляем перменную для счетчика с помощью которого мы пройдемся по массиву переобразовывая каждый символ */
	int		pow;						/* Обьявляем перменную для счетчика который будет говорить о том в какую степень возвести добытое из символа 
										 * число в зависимости от позиции ячейки добытого из символа числа */
	int		base_type;					/* Обьявляем перменную для хранения информации о базовом типе числа в строке */

	pow = 0;							/* Инициализируем нулем переменную указывающую степень */
	i = 0;								/* Инициализируем нулем переменную счетчика чтобы начать работать с массивом символов с нулевой позиции */
	negative = 1;						/* Инициализируем единицей переменную хранящую состояние. В конце функции она умножается на добытое число
										 * на случай если знак у числа в строке будет отрицательным. Это для того чтобы применить знак к добытому числу */
	num = 0;							/* Инициализируем нулем переменную для хранения добытого числа */
	base_type = ft_check_base(base);	/* Запускаем проверку соответствия базого типа устловиям и сохраняем результат в переменную */
	if(base_type)						/* Если принятый в аргументах массив с базовым типом соответсвует условиям(не равен нулю) то запускаем код ниже */
	{
		if (*str == '-')				/* Если нулевой символ равен отрицательному знаку */
		{
			i++;						/* то переходим к след ячейке */
			negative = -1;				/* А в переменную записываем (-1) чтобы потом перед возвращением добытого числа умножить его на эту переменную
										 * и получить такое же отрицательное число какое было принято на преобразование */
		}
		while (str[i])					/* Запускаем цикл который пройдется мо массиву символов(строке) и посчитает его длинну */
			i++;
		while (--i >= 0)				/* Запускаем цикл который перобразует символы в цифры и соберет их в одно число работая до тех пор пока не пройдет по всем ячейкам */
		{
			if (ft_ctoi(str[i]) != -1 && ft_ctoi(str[i]) < base_type) /* Если символ в ячейке соответствует условиям то запускаем преобразование символа */ 
				num += ft_ctoi(str[i]) * ft_pow(base_type, pow++);/* получаем из символа число и умножаем это число на его базовый тип возведенный в степень(которая
																   * равна позиции символа в строке). И в конце сохраняем все в "num", прибавля полученое к тому что
																   * там уже хранится */
		}
		return (num * negative);		/* Завершаем функцию и возвращаем полученый результат */
	}
	return (0);
}

/*#############################################################################*/

/* Функция переделки числа в нужную систему счисления. Она возвращает адресс строки с переконвертированным числом */
void	*ft_atoi_base(int nbr, char *base)
{
	int		i;								/* обьявляем счетчик для подсчета количества найденых символов*/
	int		temp;							/* обьявляем переменную для хранения числа отражающего систему счисления, которое нам будет нужно для вычислений */
	int		n[100];							/* обьявляем массив целых чисел для печати */
	char	*final;							/* Обьявляем указатель на массив для которого выделим память для хранения результата конвертирования */

	i = 0;									/* инициализируем счетчик найденых символов нулем */
	if ((temp = ft_check_base(base)))		/* Запускаем функцию проверки полученой нами в массиве "base" системы счисления условиям и сохраняем результат.
											 * Функция должна вернуть число отражающее систему счисления если все хорошо или если наоборот то ноль */
											/* Если проверка прошла успешно и мы получили число отражающее систему счисления то запускаем код внутри  */
	{
		if (nbr < 0)						/* проверяем является ли печатаемое число отрицательным */
		{
			nbr *= -1;						/* если да то умножаем его на -1 чтоб получить знак "минус" */
			ft_putchar('-');				/* и печатаем символ отрицательного числа(чтобы оно было перед тем как будет напечатано само число) */
		}
		while (nbr)							/* Пока значение переменной хранящей число не равно нулю... */
		{
			n[i] = nbr % temp;				/* ВЫЧИСЛЯЕМ с помощью temp(число отражающее систему счисления) ТО, КАК в нужной нам системе счисления выглядит число.
											 * Для этого делим nbr на temp(число отражающее систему счисления) по модулю и записывая результат в массив целых чисел.
											 * Так мы узнаем значение каждого символа в нужной нам системе счисления */

			nbr /= temp;					/* Теперь для вычисления оставшихся чисел уменьшаем само число в nbr, разделив его на 
											 * размер temp(число отражающее систему счисления) и сохраняем результат в той же переменной nbr */

			i++;							/* Увеличиваем счетчик для перехода к след ячейке. Так же переменная i нам понадобиться позже. 
											 * Накопленное в ней значение скажет нам о размере получившегося массива, которое мы используем 
											 * чтобы напечатать символы в правильном порядке. */
		}
		if ((final = malloc(sizeof(char) * (i + 1))) == ((void *)0))/* Теперь выделим память для сохранения туда результата. Сделаем память на 1 ячейку больше чем длинна 
											 * нужного массива. Мы используем это чтобы создать массив с лишней ячейкой для записи в лишнюю ячейку результируючего символа '\0' */
			return (((void *)0));			/* Если что то пошло не так(не достаточно памяти) то возвращаем NULL */
		temp = 0;							/* Используем уже не нужную переменную temp как счетчик, инициализируя ее нулем чтобы начать заполнять массив с нулевой ячейки */
		while (i > 0)						/* Запускаем цикл который восстановит порядок найденых нами значений символов и запишет их в final */
		{
			--i;							/* Уменьшаем счетчик чтобы двигаться вниз по массиву отдающему символу */
			final[temp] = base[n[i]];		/* Для этого мы используем найденные нами значения, каждой цифры числа 'nbr' сохраненные в массива 'n', как шифр
											 * к массиву хранящему значения базового типа.
											 * Мы будем вызывать числа из массива 'n' и вставлять как указатель на нужное значение.
											 * Чтобы восстановить порядок найденых нами символов(развернуть число в нормальный вид) мы будем заполнять его двигаясь
											 * по нему от начала к концу, a другой массив в это же время будет отправлять нам символы двигаясь с конца массива к началу */
			temp++;							/* Увеличиваем счетчик чтобы двигаться по результирующему массиву вверх */
		}
	}
	return (final);
}

/*#############################################################################*/

/* Функция конвертирующая строку с числом(nbr) из одной системы счисления(base_from) в другую систему счисления(base_to) */
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)/* Принимаем в аргументах строку с числом, прошлую систему счисления и желаемую систему счисления */
{
	int dec;								/* Обьявим переменную для хранния числа преобразованного из прошлой системы счисления в десятичное число */
	char *final;							/* Обьявим указатель для адреса строки с результатом конвертирования  уже из десятичной системы в нужную нам систему счисления */
											/* А теперь мы плавно и переведем строку с числом определенной системы счисления сначала в  десятичное число
											 * а потом переведем десятичное в строку с числом нужной нам системы счисления */
	dec = ft_get_dec(nbr, base_from);		/* Вызовем функцию преобразования строки с числом определенной системы счислени в десятичное число и сохраним в "dec" */
	final = ft_atoi_base(dec, base_to);		/* Вызовем функцию преобразования десятичного числа в строку с числом определенной системы счислени и полученый адрес сохраним в "final" */

	return (final);							/* Возвращаем адресс полученой строки и завершаем функцию */
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int     main(void)									/* Основаная функция */
{
	char *hex = "0123456789ABCDEF";					/* Обьявим и инициализируем строку с шестнадцатиричной системой счисления для передачи её в аргументы как тип 
													 * желаемого результата */
	char *binary = "01";							/* Обьявим и инициализируем строку с двоичной системой счисления для передачи её в аргументы как показатель того
													 * в какой системе счисления находится строки с числом "nbr" */
	char *number = "010100100101001010";			/* Обьявим и инициализруем строку содержащую число в определенной системе счисления для конвертирования */

	ft_putstr(ft_convert_base(number, binary, hex));/* Запускаем функцию(ft_convert_base) которая берет строку с числом и преобразовывает его из текущей системы счисления
													 * в желаемую систему счисления и возвращает адресс полученой строки с числом.
													 * Этот адресс мы отправляем на печать в функцию печати строки для проверки результата */
	ft_putchar('\n');								/* Печатаем символ перевода строки */
	return (0);										/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}