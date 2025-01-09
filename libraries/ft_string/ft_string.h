/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:35:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/09 13:55:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdbool.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		index_of(char c, char *str);
int		last_index_of(char c, char *str);
bool	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif