/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_grande.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:27:42 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:18:21 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_save_three(t_stack **a, t_stack **b)
{
	int	size;
	int	push;
	int	i;

	size = stack_size(*a);
	push = 0;
	i = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*a)->indice <= size / 2)
		{
			do_push(a, b, 'b');
			push++;
		}
		else
			do_rotate(a, 'a');
		i++;
	}
	while (size - push > 3)
	{
		do_push(a, b, 'b');
		push++;
	}
}

void	shift_stack(t_stack **a)
{
	int	low_pos;
	int	size;

	size = stack_size(*a);
	low_pos = get_lowest_in_pos(a);
	if (low_pos > size / 2)
	{
		while (low_pos < size)
		{
			do_reverse(a, 'a');
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			do_rotate(a, 'a');
			low_pos--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	push_all_save_three(a, b);
	sort_peque(a);
	while (*b)
	{
		get_obj_pos(a, b);
		get_cost(a, b);
		do_cheapest(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
