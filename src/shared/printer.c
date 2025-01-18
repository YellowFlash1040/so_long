/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:49:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/18 16:49:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	print_failure(char *str)
{
	ft_printf("\033[31mError\n%s ❌\n\033[0m", str);
}

void	print_success(char *str)
{
	ft_printf("\033[0;32m%s ✅\n\033[0m", str);
}
