/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:39:55 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/07 15:55:31 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*add_node(char *string, t_list **head)
{
	t_list	*node;
	t_list	*prev_node;

	node = *head;
	while (node)
	{
		prev_node = node;
		node = node->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = string;
	node->next = NULL;
	if (*head)
		prev_node->next = node;
	else
		*head = node;
	return (node);
}

t_list	*add_node_front(char *string, t_list **head)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = string;
	node->next = *head;
	*head = node;
	return (node);
}

void	clear_list(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free((*head)->value);
		free(*head);
		*head = temp;
	}
}
