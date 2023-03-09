/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:22:56 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:50:13 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_high_ind(t_stack *stack)
{
	int	indice;

	indice = stack->indice;
	while (stack)
	{
		if (stack->indice > indice)
			indice = stack->indice;
		stack = stack->next;
	}
	return (indice);
}

void	sort_peque(t_stack **stack)
{
	int	high;

	if (is_sorted(*stack))
		return ;
	high = find_high_ind(*stack);
	if ((*stack)->indice == high)
		do_rotate(stack, 'a');
	else if ((*stack)->next->indice == high)
		do_reverse(stack, 'a');
	if ((*stack)->indice > (*stack)->next->indice)
		do_swap(*stack, 'a');
}
