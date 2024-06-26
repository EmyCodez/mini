/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:01 by emilin            #+#    #+#             */
/*   Updated: 2024/03/27 16:39:50 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static void	remove_env_node(t_env **env_list, char *key)
{
	t_env	*temp;
	t_env	*current;

	temp = *env_list;
	current = NULL;
	while (temp && ft_strcmp(temp->key, key) != 0)
	{
		current = temp;
		temp = temp->next;
	}
	if (!temp)
		return ;
	current->next = temp->next;
	free_env_node(temp);
}

void	unset(char **argv, t_env **env_list, int *exit_status)
{
	int		i;
	t_env	*head;

	i = 0;
	while (argv[++i])
	{
		if (!is_valid_key(argv[i]))
		{
			ft_putstr_fd("minishell: unset: '", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("' : not a valid identifier\n", 2);
			*exit_status = 1;
		}
		else
		{
			head = *env_list;
			if (ft_strcmp((*env_list)->key, argv[i]) == 0)
			{
				*env_list = (*env_list)->next;
				free_env_node(head);
				return ;
			}
			remove_env_node(env_list, argv[i]);
		}
	}
}
