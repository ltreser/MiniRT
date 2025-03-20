
#include "../include/miniRT.h"


// was ist besser, coordinate system an untere Seite des Bildschirms und neu berechung der coordinaten oder


int	main(int argc, char **argv)
{
	printf("\n\n\nTESTING: %s\n\n", argv[1]);
	t_rt *rt;
	struct timeval	start, end;
	gettimeofday(&start, NULL);
	rt = malloc(sizeof(t_rt));
	init(rt);
	if (input_correct(rt, argc, argv))
	{
		parse_input(rt, argv);
		mlx_create_window(rt);
		render(rt);
		

	}
	gettimeofday(&end, NULL);
	double runtime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
	ft_gc_free(rt->gc);
	free(rt);
	printf("Runtime: %.6f seconds\n", runtime);
	return (0);
}
