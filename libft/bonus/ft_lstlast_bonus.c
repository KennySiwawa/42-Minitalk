/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:02:31 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:02:33 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Find the last node of a list.
 *
 * @param lst The beginning of the list.
 * @return The last node of the list, or NULL if the list is empty.
 *
 * @details Traverses the list starting from
 * 'lst' and returns a pointer to the last node.
 * Returns NULL if 'lst' is NULL (empty list).
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

/**int main()
{
	t_list      *list;
	int         *value1;
	int         *value2;

	value1 = (int *)malloc(sizeof(int));
	if (value1 == NULL)
		return (1);
	list = ft_lstnew(value1);
	if (list == NULL)
		return (1);
	*value1 = 45;
	value2 = (int *)malloc(sizeof(int));
	if (value2 == NULL)
		return (1);
	*value2 = 54;
	t_list *new = ft_lstnew(value2);
	if (new == NULL)
		return (1);
	list -> next = new;
	t_list *last_node = ft_lstlast(list);
	if (last_node != NULL)
	{
		printf("The last node is %d\n", *(int *)last_node -> content);
	}
	free (value1);
	free (list);
	free (value2);
	free (new);
}*/