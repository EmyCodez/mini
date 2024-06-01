/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:30:33 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/01 12:41:01 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static void	sigint_handler(int num)
// {
// 	(void)num;
// 	if (g_minishell.signint_child)
// 	{
// 		ft_putstr_fd("\n", 1);
// 		g_minishell.signint_child = 0;
// 		g_minishell.heredoc_sigint = 1;
// 	}
// 	else
// 	{
// 		ft_putstr_fd("\n", 1);
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// }

void	ft_sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}
