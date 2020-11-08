/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 02:01:06 by eliott            #+#    #+#             */
/*   Updated: 2020/11/08 12:25:56 by eliott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define BUF_SIZE 4096

int		ft_mesure_file(char *path)
{
	int size;
	int fd;
	int rd;
	char buf[BUF_SIZE];

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((rd = read(fd, buf, BUF_SIZE)))
		size += rd;
	if (close(fd) == -1)
		return (-1);
	return (size);
}

int		ft_count_strs(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
		{
			count++;
			while (str[i] && str[i] != '\n')
				i++;
		}
	}
	return (count);
}

void	ft_free_file(char **file)
{
	int i;

	i = 0;
	while(file[i])
		free(file[i++]);
}

char	*ft_ndup(char *str, int start, int end)
{
	char	*dup;
	int		i;

	dup = (char *)malloc((end - start + 1) * sizeof(char));
	i = 0;
	while (start + i < end)
	{
		dup[i] = str[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		start;
	int		s;
	int		i;

	i = 0;
	s = 0;
	tab = (char **)malloc((ft_count_strs(str) + 1) * sizeof(char *));
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
		{
			start = i;
			while (str[i] && str[i] != '\n')
				i++;
			tab[s++] = ft_ndup(str, start, i);
		}
	}
	tab[s] = 0;
	return (tab);
}

char	**ft_get_file(char *path)
{
	char	*full_file;
	char	**ret;
	int		size;
	int		fd;
	int		rd;

	size = ft_mesure_file(path);
	full_file = (char*)malloc(sizeof(char) * (size + 1));
	if (!full_file)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	rd = read(fd, full_file, size);
	full_file[rd] = '\0';
	ret = ft_split(full_file);	
	free(full_file);
	return (ret);
}
