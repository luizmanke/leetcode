#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparator(const void * number_1, const void * number_2) { 
    return (*(int *) number_1 - *(int *) number_2);
}

double findMedianSortedArrays(int * array_1, int size_1, int * array_2, int size_2){
    int full_size = size_1 + size_2;

    // Join arrays
    int * full_array = (int *) malloc(full_size * sizeof(int));
    memcpy(full_array, array_1, size_1 * sizeof(int));
    memcpy(full_array + size_1, array_2, size_2 * sizeof(int));

    // Sort array
    qsort((void *) full_array, full_size, sizeof(int), comparator);

    // Get median
    double median;
    int index = full_size / 2;
    if (full_size % 2 == 0) {
        median = (full_array[index] + full_array[index-1]) / 2.0;
    } else {
        median = full_array[index];
    }

    return median;
}

int main() {
    int size_1 = 3;
    int array_1[3] = {1, 3, 4};
    int size_2 = 1;
    int array_2[1] = {2};

    double median = findMedianSortedArrays(array_1, size_1, array_2, size_2);
    printf("median: %f", median);

    return 0;
}
