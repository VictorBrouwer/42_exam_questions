/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_biggest_pal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:10:28 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/14 18:18:13 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

int    	get_biggest_pal(char *s);
size_t	ft_strlen(const char *c);
int		ft_str_comp(int i, int j, char *s);


int main(int argc, char **argv)
{
	if (argc == 2)
		get_biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}

int    get_biggest_pal(char *s)
{
	int str_len, i, j;

	i = 0;
	str_len = ft_strlen(s);
	while (str_len - i > 0)
	{
		j = i;
		while (j >= 0)
		{
			if (ft_str_comp(j, (str_len - i + j - 1), s) == 0)
			{
				printf("len = %d", (str_len - i));
				return (write(1, &s[j], (str_len - i)));
			}
			j--;
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_str_comp(int i, int j, char *s)
{
	while (i < j)
	{
		if (s[i] != s[j])
			return (-1);
		i++;
		j--;
	}
	return (0);
}