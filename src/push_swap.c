/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:02 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 02:25:05 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		printf("%d: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
}

int	main(void)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = create_stack(1, 125);
	stacka->next = create_stack(2, 1258);
	stacka->next->next = create_stack(3, 12893);
	printf("=========STACK A===========\n");
	print_stack(stacka);
	swap_stack_a(stacka);
	printf("=========STACK A===========\n");
	print_stack(stacka);

	printf("=========STACK B===========\n");
	stackb = create_stack(1, 1);
	stackb->next = create_stack(2, 2);
	stackb->next->next = create_stack(3, 3);
	print_stack(stackb);


	printf("FIRST\n");

	rotate_stack_a(&stacka);
	printf("=========STACK A===========\n");
	print_stack(stacka);
	printf("=========STACK B===========\n");
	print_stack(stackb);


	rotate_stack_a(&stacka);
	printf("=========STACK A===========\n");
	print_stack(stacka);
	printf("=========STACK B===========\n");
	print_stack(stackb);



	rotate_stack_b(&stackb);
	printf("=========STACK A===========\n");
	print_stack(stacka);
	printf("=========STACK B===========\n");
	print_stack(stackb);


	reverse_rotate_stack_a(&stacka);
	printf("=========STACK A===========\n");
	print_stack(stacka);
	printf("=========STACK B===========\n");
	print_stack(stackb);


	reverse_rotate_stack_a(&stacka);
	printf("=========STACK A===========\n");
	print_stack(stacka);
	printf("=========STACK B===========\n");
	print_stack(stackb);



	reverse_rotate_stack_b(&stackb);
	printf("=========STACK A===========\n");
	print_stack(stacka);
	printf("=========STACK B===========\n");
	print_stack(stackb);


	destroy_stack(&stacka);
	destroy_stack(&stackb);
	return (0);
}
