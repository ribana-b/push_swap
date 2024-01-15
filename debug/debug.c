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
