/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:58:54 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/11 07:25:25 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

static	void	ll_initialize(t_ll **ll)
{
	if (!(*ll))
		return ;
	(*ll)->content = NULL;
	(*ll)->next = NULL;
	return ;
}

t_ll	*ll_create_node(void)
{
	t_ll	*ll;

	ll = (t_ll *)malloc(sizeof(t_ll));
	if (!ll)
		return (NULL);
	ll_initialize(&ll);
	return (ll);
}

void	ll_add_node(t_ll **ll)
{
	t_ll	*newnode;

	if (!(*ll))
		return ;
	newnode = ll_create_node();
	if (!newnode)
		return ;
	(*ll)->next = newnode;
}

t_ll	*ll_generator(int length)
{
	t_ll	*ll;
	t_ll	*temp;

	if (length < 1)
		return (NULL);
	ll = ll_create_node();
	if (!ll)
		return (NULL);
	if (length == 1)
		return (ll);
	temp = ll;
	while (length-- > 1)
	{
		ll_add_node(&temp);
		if (!temp->next)
		{
			ll_destroy(&ll);
			return (NULL);
		}
		temp = temp->next;
	}
	return (ll);
}
