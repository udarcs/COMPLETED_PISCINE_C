/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** *
 *
 * 
 *	• Создайте функцию ft_list_size, которая возвращает количество элементов в 
 *	списке.
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *											int	ft_list_size(t_list *begin_list)
 * 
 * ************************************************************************** *
 * 
 *	••• P.S нас просят создать функцию, которая посчитает количество связанных 
 *	между собой экземпляров структур типа t_list
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		i;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	if (list)
	{
		i = 1;
		while (list->next)
		{
			list = list->next;
			i += 1;
		}
	}
	return (i);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
