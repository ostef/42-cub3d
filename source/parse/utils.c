/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:44:24 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/02 15:44:54 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_s64	skip_spaces(t_cstr str)
{
	t_s64	i;

	i = 0;
	while (str[i] && str[i] != '\n' && ft_is_space (str[i]))
		i += 1;
	return (i);
}

t_s64	skip_until_newline(t_cstr str)
{
	t_s64	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i += 1;
	return (i);
}
