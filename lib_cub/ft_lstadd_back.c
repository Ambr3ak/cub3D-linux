/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:47:52 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:47:53 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	list = *alst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*alst = new;
}
