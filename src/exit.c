/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:06 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/13 16:28:56 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/* void	free_all(t_rt *rt)
{
	return ;
} */

void	ft_exit(t_rt *rt, int exit_code, char *error_message)
{
	perror(error_message);
	free(error_message);
	ft_gc_free(rt->gc);
	free(rt);
	exit(exit_code);
}
