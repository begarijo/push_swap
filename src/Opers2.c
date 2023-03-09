/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Opers2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:13:47 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 13:01:16 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Traslada los números una posición hacia arriba*/

void	do_reverse(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*penulti;

	bottom = get_bottom(*stack);
	penulti = get_penulti(*stack);
	tmp = *stack;
	*stack = bottom;
	(*stack)->next = tmp;
	penulti->next = NULL;
	if (c == 'a')
		ft_putstr("rra\n");
	if (c == 'b')
		ft_putstr("rrb\n");
}

void	do_rrr(t_stack **a, t_stack **b)
{
	do_reverse(a, 'r');
	do_reverse(b, 'r');
	ft_putstr("rrr\n");
}
