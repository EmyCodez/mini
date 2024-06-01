/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:47:32 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/01 12:38:21 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/* Readline library headers */
# include <readline/history.h>
# include <readline/readline.h>

/* Libraries from includes folder */
# include "builtins.h"
# include "env.h"
# include "execution.h"
# include "parsing.h"
# include "signals.h"
# include "tokenizer.h"

/* --- free.c --- */
void	free_ptr(void *ptr);
void	free_2d_array(char **arr);
void	free_exit(t_shell *myshell, int *exit_status);

# define PROMPT_MSG "\033[1;36mminishell\033[34m$ \033[0m"

/* --- valid_utils.c --- */
int		is_space(char c);
int		is_empty_str(char *str);
int		is_quote(char c);
int		is_valid_input(char *buff);
#endif