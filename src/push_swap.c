/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:36:23 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:51:01 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->valor > stack->next->valor)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		do_swap(*a, 'a');
	else if (size == 3)
		sort_peque(a);
	else if (size > 3 && !is_sorted(*a))
		sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		return (0);
	if (!is_correct(argv))
		exit_error(NULL, NULL);
	b = NULL;
	a = fill_stack(argc, argv);
	size = stack_size(a);
	assign_indice(a, size + 1);
	push_swap(&a, &b, size);
	free_stack(&a);
	free(&b);
	return (0);
}
