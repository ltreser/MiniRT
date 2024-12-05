
#include "../include/miniRT.h"

void	parse_dimensions(t_rt *rt, char *str)
{
	int i;

	i = skip_spaces(str);
	rt->obj[rt->n_obj]->cylinder->d = ft_atof(gc_chop(rt->gc, str + i, ' '));
	i = skip_spaces(str);
	rt->obj[rt->n_obj]->cylinder->h = ft_atof(gc_chop(rt->gc, str + i, ' '));
	if (str)
	{
		free(str);
		str = NULL;
	}
}

int	skip_spaces(char *str)
 {
		int	i;

		i = 0;
		while (str[i] == ' ')
			i++;
		return(i);
}

int	only_valid_chars(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == 'A' || str[i] == 'C' || str[i] == 'L' || str[i] == 'c' || str[i] == 's' || str[i] == 'p'))
			i++;
		else if (i == 1 && (str[i] == 'l' || str[i] == 'y' || str[i] == 'p' || str[i] == ' '))
			i++;
		else if (str[i] == ',' || str[i] == '-' || str[i] == '.' || ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

void	is_nan(t_rt *rt, float f)
{
	if (isnan(f))
	{
		perror(FORMAT_FAIL);
		perror("NAN returned by ft_atof\n");
		ft_gc_free(rt->gc);
		exit(EXIT_INPUT);
	}
}
