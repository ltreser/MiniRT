#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct						s_vector
{
	float					x;
	float					y;
	float					z;
};
typedef struct s_vector		t_vector;

float v_len(t_vector vector)
{
	return (sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}
t_vector	v_normalize_nm(t_vector v)
{
	float	length;

	length = 0;
	length = v_len(v);
	if (length == 0)
		return (v);
	v.x /= length;
	v.y /= length;
	v.z /= length;
	return (v);
}
void	print_vector(t_vector v, char *prompt)
{
	printf("vector %s x:%f y:%f z:%f\n", prompt, v.x, v.y, v.z);
	printf("%f,%f,%f\n", v.x, v.y, v.z);

}

int main(int argc, char *argv[])
{
	t_vector vector;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s x1 x2 x3 ...\n", argv[0]);
        return 1;
    }

        vector.x = atof(argv[1]);
        vector.y= atof(argv[2]);
        vector.z = atof(argv[3]);
		vector = v_normalize_nm(vector);
		print_vector(vector, "vector");
    return 0;
}
