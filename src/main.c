/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:31:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 14:12:08 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_toolkit.h"

int	main(void)
{
	char	*filepath;
	char	processing_result;

	filepath = "maps/path_check/map5.ber";
	processing_result = process_map(filepath);
	if (processing_result != 0)
		return (processing_result);
	return (0);
}
