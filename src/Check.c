/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:29:12 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:12:40 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Comprueba que los arg sean números, que no haya sólo un signo sin nº detrás.*/

int	arg_is_num(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

/*Comprueba que hay dobles en los argumentos*/

int	hay_dobles(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && is_duplic(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*En caso de que delante del 0 haya un signo lo ignora,
 *y comprueba que haya ceros y no cualquier otra cosa*/

int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/*Una vez con todas las comprobaciones, los ceros se irán sumando,
 *en caso de que haya más de uno devuelve 0.
 Si no son num los arg devuelve 0. Y si hay dobles también devuelve 0.*/

int	is_correct(char **argv)
{
	int	i;
	int	ceros;

	ceros = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_num(argv[i]))
			return (0);
		ceros += arg_is_zero(argv[i]);
		i++;
	}
	if (ceros > 1)
		return (0);
	if (hay_dobles(argv))
		return (0);
	return (1);
}
