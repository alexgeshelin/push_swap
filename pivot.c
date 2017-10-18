/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:13:36 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/14 15:13:37 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_pivot(t_stack *a, int size, int *r)
{
	int		*array;
	int		i;

	array = (int*)malloc(sizeof(int) * size);
	i = 0;
	*r = 0;
	while (i < size)
	{
		array[i] = a->n;
		a = a->next;
		i++;
	}
	ft_qsort(array, 0, size - 1);
	i = array[size / 2];
	free(array);
	return (i);
}

void	ft_qsort(int *arr, int start, int end)
{
	int j;
	int i;
	int pivot;

	if (end - start < 1)
		return ;
	i = start + 1;
	j = start + 1;
	pivot = alt_find_pivot(&(arr[start]), start, end);
	swaper(&(arr[start]), &(arr[pivot]));
	while (i <= end)
	{
		if (arr[i] < arr[start])
		{
			swaper(&(arr[i]), &(arr[j]));
			j++;
		}
		i++;
	}
	swaper(&(arr[start]), &(arr[j - 1]));
	ft_qsort(arr, start, j - 2);
	ft_qsort(arr, j, end);
}

void	swaper(int *i, int *j)
{
	int b;

	b = *i;
	*i = *j;
	*j = b;
}

int		alt_find_pivot(int *arr, int start, int end)
{
	int first;
	int middle;
	int last;

	first = start;
	middle = (end + start) / 2;
	last = end;
	if (arr[first] > arr[middle])
		swaper(&first, &middle);
	if (arr[middle] > arr[last])
		swaper(&middle, &last);
	if (arr[first] > arr[middle])
		swaper(&first, &middle);
	return (middle);
}
