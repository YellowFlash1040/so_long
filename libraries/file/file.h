/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:35:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 17:35:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "../get_next_line/get_next_line.h"
# include "../list/list.h"
# include "../string/string.h"
# include <fcntl.h>
# include <stdlib.h>

char	*get_file_extension(char *filepath);
char	**read_all_lines(char *filepath);
bool	file_exists(const char *filepath);

#endif