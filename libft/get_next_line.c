/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:25:50 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/11 10:37:47 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void			free_tmp(t_lst **lst, t_lst *tmp)
{
	t_lst	*bef;
	t_lst	*nxt;

	bef = (*lst);
	nxt = tmp->next;
	if ((*lst) == tmp)
		(*lst) = (*lst)->next;
	else
	{
		while (bef && bef->next != tmp)
			bef = bef->next;
		if (nxt == NULL)
			bef->next = NULL;
		else
			bef->next = nxt;
	}
	free(tmp->txt);
	free(tmp);
}

static char		*get_line(t_lst *tmp)
{
	int		i;
	char	*new;
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmptxt;

	i = 0;
	while (ft_strchr(tmp->txt, '\n') == NULL &&
			(ret = read(tmp->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmptxt = tmp->txt;
		tmp->txt = ft_strjoin(tmptxt, buff);
		free(tmptxt);
	}
	if (ret == -1)
		return (NULL);
	while (tmp->txt && tmp->txt[i] != '\n' && tmp->txt[i] != '\0')
		i++;
	if ((new = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	if (tmp->txt)
		new = ft_strncpy(new, tmp->txt, (size_t)i);
	new[i] = '\0';
	return (new);
}

static t_lst	*new_fd(int fd, t_lst **lst)
{
	t_lst	*new;
	t_lst	*tmp;

	tmp = (*lst);
	if (fd < 0)
		return (NULL);
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	if ((new = (t_lst *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->next = NULL;
	new->txt = NULL;
	new->fd = fd;
	if ((*lst) == NULL)
		(*lst) = new;
	else
		tmp->next = new;
	return (new);
}

int				get_next_line(int fd, char **line)
{
	static t_lst	*lst = NULL;
	t_lst			*tmp;
	char			*tmptxt;

	tmp = lst;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		if ((tmp = new_fd(fd, &lst)) == NULL)
			return (-1);
	}
	if (!(line) || (*line = get_line(tmp)) == NULL)
		return (-1);
	if (!(tmp->txt) || !(ft_strcmp(tmp->txt, "\0")) ||
			ft_strcmp(tmp->txt, "\0") == 3 || ft_strcmp(tmp->txt, "\0") == 16)
	{
		free_tmp(&lst, tmp);
		return (0);
	}
	tmptxt = tmp->txt;
	tmp->txt = ft_strsub(tmptxt, (ft_strlen(*line) + 1), ft_strlen(tmp->txt));
	free(tmptxt);
	return (1);
}
