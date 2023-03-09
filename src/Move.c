/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:38:29 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:14:59 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

void	do_rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

void	do_ra(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rotate(a, 'a');
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_reverse(a, 'a');
			(*cost)++;
		}
	}
}

void	do_rb(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rotate(b, 'b');
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_reverse(b, 'b');
			(*cost)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr_both(a, b, &cost_a, &cost_b);
	do_ra(a, &cost_a);
	do_rb(b, &cost_b);
	do_push(b, a, 'a');
}
