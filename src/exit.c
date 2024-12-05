/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:06 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/05 20:16:44 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	free_all(t_rt *rt)
{
	return ;
}

void	ft_exit(t_rt *rt, int exit_code, char *error_message)
{
	perror(error_message);
	free(error_message);
	free_all(rt);
	exit(exit_code);
}
