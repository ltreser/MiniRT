/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:24:50 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/05 19:25:01 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_words(char *s, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			words++;
			in_word = 1;
		}
		s++;
	}
	return (words);
}
