/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inic.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:12 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:14:45 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Con los argumentos recibidos y la cantidad de argumentos, 
 * comprueba que haya más de un argumento, 
 * los numeros de argv los pasa a enteros y comprueba que no exceda los límites.
 * Crea un nuevo stack a, y va añadiendo al final uno a uno los valores*/

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*a;
	int		num;
	int		i;

	a = NULL;
	num = 0;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_error(&a, NULL);
		if (i == 1)
			a = new_stack(num);
		else
			add_bottom(&a, new_stack(num));
		i++;
	}
	return (a);
}

/*Cuando ya se ha rellenado el stack a, se asigna un índice a cada número.
 * Este índice va de menor a mayor, es decir index(INT_MIN) = 1 
 * y index(INT_MAX) = size del stack*/

void	assign_indice(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*mayor;
	int		valor;

	while (--size > 0)
	{
		ptr = a;
		valor = INT_MIN;
		mayor = NULL;
		while (ptr)
		{
			if (ptr->valor == INT_MIN && ptr->indice == 0)
				ptr->indice = 1;
			if (ptr->valor > valor && ptr->indice == 0)
			{
				valor = ptr->valor;
				mayor = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (mayor != NULL)
			mayor->indice = size;
	}
}
