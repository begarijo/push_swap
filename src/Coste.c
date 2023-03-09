/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:27:15 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:19:36 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Calcula el coste de movimientos de cada elemento de B
 * a su punto correspondiente en A.
 * Se calculan dos costes:
 * cost_b: Coste de mover ese elemento al inicio del stack B.
 * cost_a: Que es el coste de enviarlo a la posición correcta en A,
 * desde la primera pos en B.
 * Si el elemento está en la mitad inferior del stack el coste será negativo,
 * y si no, será positivo.*/

void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->posic;
		if (tmp_b->posic > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->posic) * -1;
		tmp_b->cost_a = tmp_b->pos_obj;
		if (tmp_b->pos_obj > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->pos_obj) * -1;
		tmp_b = tmp_b->next;
	}
}

/*En caso de que la suma de ambos costes sea MENOR que el más barato,
 * lo irá cambiando, hasta que el más barato sea MÁS PEQUEÑO
 * que la suma de estos, y mover tanto en a como en b
 * con esos costes actualizados a los más bajos.*/

void	do_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheap;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheap = INT_MAX;
	while (tmp)
	{
		if (num_absol(tmp->cost_a) + num_absol(tmp->cost_b) < num_absol(cheap))
		{
			cheap = num_absol(tmp->cost_a) + num_absol(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}
