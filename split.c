/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-hmi <zait-hmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:20:05 by zait-hmi          #+#    #+#             */
/*   Updated: 2025/04/07 20:23:21 by zait-hmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[*cursor + len] && s[*cursor + len] != c)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (i < len)
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

static int	fill_result_array(char **result_array, char *s, char c, int words_n)
{
	int	i;
	int	cursor;

	i = 0;
	cursor = 0;
	while (i < words_n)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
		{
			while (i > 0)
				free(result_array[--i]);
			free(result_array);
			return (0);
		}
		i++;
	}
	result_array[i] = NULL;
	return (1);
}

char	**split(char *s, char c)
{
	int		words_n;
	char	**result_array;

	if (!s)
		return (NULL);
	words_n = count_words(s, c);
	if (words_n == 0)
	{
		result_array = malloc(sizeof(char *));
		if (!result_array)
			return (NULL);
		result_array[0] = NULL;
		return (result_array);
	}
	result_array = malloc(sizeof(char *) * (words_n + 1));
	if (!result_array)
		return (NULL);
	if (!fill_result_array(result_array, s, c, words_n))
		return (NULL);
	return (result_array);
}

void	free_split_result(char **result_array)
{
	int	i;

	i = 0;
	if (!result_array)
		return ;
	while (result_array[i])
	{
		free(result_array[i]);
		i++;
	}
	free(result_array);
}
