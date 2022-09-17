/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:23:38 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/17 16:17:48 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen(char *s)
{
	int	len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

// strdup
// strjoin
// strchr
// lstdel