/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:21:43 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:17:32 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack *stack, char c)
{
	int	tmp;

	if (c == 'a')
		ft_putstr("sa\n");
	if (c == 'b')
		ft_putstr("sb\n");
	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->valor;
	stack->valor = stack->next->valor;
	stack->next->valor = tmp;
	tmp = stack->indice;
	stack->indice = stack->next->indice;
	stack->next->indice = tmp;
}

void	do_ss(t_stack **a, t_stack **b)
{
	do_swap(*a, 'x');
	do_swap(*b, 'x');
	ft_putstr("ss\n");
}

/*Traslada el primer número de un stack al otro,
 * también en la primera posición disponible.*/

void	do_push(t_stack **src, t_stack **dst, char c)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
	if (c == 'a')
		ft_putstr("pa\n");
	if (c == 'b')
		ft_putstr("pb\n");
}

/*Traslada los nº a la siguiente posición, es decir, 
 * + 1 posición abajo, siendo el que era el último, ahora el primero.*/

void	do_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*bottom;

	tmp = *stack;
	*stack = (*stack)->next;
	bottom = get_bottom(*stack);
	tmp->next = NULL;
	bottom->next = tmp;
	if (c == 'a')
		ft_putstr("ra\n");
	if (c == 'b')
		ft_putstr("rb\n");
}

void	do_rr(t_stack **a, t_stack **b)
{
	do_rotate(a, 'r');
	do_rotate(b, 'r');
	ft_putstr("rr\n");
}
