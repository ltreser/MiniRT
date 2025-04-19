/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:45:36 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/19 21:27:29 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	ft_exit(t_rt *rt, int exit_code, char *error_message)
{
	perror(error_message);
	ft_gc_free(rt->gc);
	free(rt);
	exit(exit_code);
}
