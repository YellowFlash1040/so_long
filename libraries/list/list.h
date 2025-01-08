/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:15:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/07 15:53:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct list
{
	char		*value;
	struct list	*next;
}				t_list;

t_list			*add_node(char *string, t_list **head);
t_list			*add_node_front(char *string, t_list **head);
void			clear_list(t_list **head);

#endif