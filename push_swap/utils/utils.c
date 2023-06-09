/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:01:24 by angassin          #+#    #+#             */
/*   Updated: 2023/04/04 15:36:32 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
	Displays "Error" followed by a ’\n’ on the standard error 
	and exit	
*/
void	error_exit(t_stack	*stack)
{
	if (stack)
	{
		lstclear(&stack->a);
		lstclear(&stack->b);
	}
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/* 
	Returns an index number in ascending order according to the value
	sent in parameter.
*/
int	index_order(t_node *node, int value)
{
	int	index;

	index = 0;
	while (node)
	{
		if (value > node->value)
			index++;
		node = node->next;
	}
	return (index);
}

/*
	Returns the rank (which spot in the list) of the node containing the index
	sent in parameter.
*/
int	ranking(t_node *node, int index)
{
	int	rank;

	rank = 0;
	while (node != NULL)
	{
		if (node->index == index)
			return (rank);
		rank++;
		node = node->next;
	}
	return (-1);
}

/* Finds the smallest index of the list */
int	find_min(t_node *node)
{
	int	min;

	min = INT_MAX;
	while (node != NULL)
	{
		if (node->index < min)
			min = node->index;
		node = node->next;
	}
	return (min);
}
