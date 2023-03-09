/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:48:08 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:50:36 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Incializa y crea un nuevo stack.*/

t_stack	*new_stack(int valor)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->valor = valor;
	new->indice = 0;
	new->posic = -1;
	new->pos_obj = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/*Busca la última posición de un elemento del stack y la devuelve*/

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*Busca la PENULTIMA posición de un elemento en el stack y la devuelve*/

t_stack	*get_penulti(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/*Añade al final de un stack un elemento nuevo*/

void	add_bottom(t_stack **stack, t_stack *nuevo)
{
	t_stack	*bottom;

	if (!nuevo)
		return ;
	if (!*stack)
	{
		*stack = nuevo;
		return ;
	}
	bottom = get_bottom(*stack);
	bottom->next = nuevo;
}

/*Calcula el tamaño del stack*/

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
