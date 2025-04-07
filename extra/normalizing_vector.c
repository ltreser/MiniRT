#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//AI CODE
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s x1 x2 x3 ...\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    double *vec = malloc(n * sizeof(double));
    if (vec == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    double magnitude = 0.0;

    // Parse input and compute magnitude
    for (int i = 0; i < n; i++) {
        vec[i] = atof(argv[i + 1]);
        magnitude += vec[i] * vec[i];
    }

    magnitude = sqrt(magnitude);
    if (magnitude == 0.0) {
        fprintf(stderr, "Cannot normalize a zero vector.\n");
        free(vec);
        return 1;
    }

    // Normalize and print
    printf("Normalized vector: ");
    for (int i = 0; i < n; i++) {
        printf("%.6f ", vec[i] / magnitude);
    }
    printf("\n");

    free(vec);
    return 0;
}
