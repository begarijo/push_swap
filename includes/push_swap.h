/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begarijo <begarijo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:01:00 by begarijo          #+#    #+#             */
/*   Updated: 2023/02/15 18:11:48 by begarijo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*Estructura para guardar valores que vamos a ir utilizando*/

typedef struct s_stack
{
	int				valor;
	int				indice;
	int				posic;
	int				pos_obj;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*Utils*/

int		ft_atoi(char *s);
void	ft_putstr(char *s);
int		is_digit(char c);
int		is_sign(char c);
int		num_absol(int n);
void	free_stack(t_stack **stack);
void	exit_error(t_stack **a, t_stack **B);
int		is_duplic(char *s1, char *s2);

/*Check Arg*/

int		arg_is_num(char *argv);
int		hay_dobes(char **argv);
int		arg_is_zero(char *argv);
int		is_correct(char **argv);

/*Posicionnes, buscar objetivo, bajo indice, etc*/

void	get_position(t_stack **stack);
int		get_lowest_in_pos(t_stack **stack);
int		get_objetivo(t_stack **a, int b_ind, int obj_ind, int obj_pos);
void	get_obj_pos(t_stack **a, t_stack **b);

/*Coste*/

void	get_cost(t_stack **a, t_stack **b);
void	do_cheapest(t_stack **a, t_stack **b);

/*Movimiento*/

void	do_rrr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	do_rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	do_ra(t_stack **a, int *cost);
void	do_rb(t_stack **b, int *cost);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/*Orden peque*/

int		find_high(t_stack *stack);
void	sort_peque(t_stack **stack);

/*Orden grande*/

void	push_all_save_three(t_stack **a, t_stack **b);
void	shift_stack(t_stack **a);
void	sort(t_stack **a, t_stack **b);

/*Operac*/

void	do_swap(t_stack *stack, char c);
void	do_ss(t_stack **a, t_stack **b);
void	do_push(t_stack **src, t_stack **b, char c);
void	do_rotate(t_stack **stack, char c);
void	do_rr(t_stack **a, t_stack **b);
void	do_reverse(t_stack **stack, char c);
void	do_rrr(t_stack **a, t_stack **b);

/*Funciones para el stack*/

t_stack	*new_stack(int valor);
t_stack	*get_bottom(t_stack *stack);
t_stack	*get_penulti(t_stack *stack);
void	add_bottom(t_stack **stack, t_stack *nuevo);
int		stack_size(t_stack *stack);

/*Inicializar: rellenar y asignar indices en a*/

t_stack	*fill_stack(int argc, char **argv);
void	assign_indice(t_stack *a, int size);

/*MAIN*/

int		is_sorted(t_stack *stack);
void	push_swap(t_stack **a, t_stack **b, int size);

#endif
