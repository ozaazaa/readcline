/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cline_clipboard_utilities.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:25:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/14 16:25:58 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readcline.h"

void	cline_clipboard(t_read *config)
{
	int length;

	if (IS_PASTE(config->buffer))
		cline_insert(config, *config->clipboard);
	else if (IS_COPY(config->buffer) || IS_CUT(config->buffer))
	{
		if (!F_GET(config->flags, F_CLIPBOARD))
		{
			F_SET(config->flags, F_CLIPBOARD);
			config->clipboard_offset = config->position;
		}
		else
		{
			free(*config->clipboard);
			length = config->position - config->clipboard_offset;
			*config->clipboard = ft_strsub(*config->context,
			config->clipboard_offset, length);
			F_UNSET(config->flags, F_CLIPBOARD);
			cline_delete(config, length);
			if (IS_COPY(config->buffer))
				cline_insert(config, *config->clipboard);
		}
	}
}
