/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middlewares.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:13:49 by merras            #+#    #+#             */
/*   Updated: 2019/10/20 22:35:10 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readcline.h"

int	termcaps_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}
