/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Posic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:04:46 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:20:19 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Asigna posiciones a los elementos del stack, guardándolos en 
 * la variable posic que está en nuestra estructura.*/

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->posic = i;
		tmp = tmp->next;
		i++;
	}
}

/*Colocamos el máximo índice como punto de partida,
 * tomamos la posición mayor y vamos comparando tamaños de índice
 * para devolver la posición del índice MÁS PEQUEÑO*/

int	get_lowest_in_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		low_ind;
	int		low_pos;

	tmp = *stack;
	low_ind = INT_MAX;
	get_position(stack);
	low_pos = tmp->posic;
	while (tmp)
	{
		if (tmp->indice < low_ind)
		{
			low_ind = tmp->indice;
			low_pos = tmp->posic;
		}
		tmp = tmp->next;
	}
	return (low_pos);
}

/*Busca la posición objetivo hacia donde poner el número.
 * Compara los índices, el que tiene, como el que debería tener.
 * En caso de que el índice de ese valor sea mayor que el que tiene en b
 * y menor que el objetivo, lo va reemplazando, tanto el índice objetivo,
 * como la posición. Devuelve la posición hacia la que debe ir*/

int	get_objetivo(t_stack **a, int b_ind, int obj_ind, int obj_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->indice > b_ind && tmp_a->indice < obj_ind)
		{
			obj_ind = tmp_a->indice;
			obj_pos = tmp_a->posic;
		}
		tmp_a = tmp_a->next;
	}
	if (obj_ind != INT_MAX)
		return (obj_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->indice < obj_ind)
		{
			obj_ind = tmp_a->indice;
			obj_pos = tmp_a->posic;
		}
		tmp_a = tmp_a->next;
	}
	return (obj_pos);
}

/*Asigna para cada elemento de A
 * una posición objetivo donde debe ir.
 * Esa posición es el punto donde debe ir el elemento en el stack B
 * para poder ordenar bien. Estas posiciones se usarán para
 * calcular el coste de los movimientos de cada elemento
 * a su posición objetivo en A*/

void	get_obj_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		pos_obj;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	pos_obj = 0;
	while (tmp_b)
	{
		pos_obj = get_objetivo(a, tmp_b->indice, INT_MAX, pos_obj);
		tmp_b->pos_obj = pos_obj;
		tmp_b = tmp_b->next;
	}
}
