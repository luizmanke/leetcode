/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int nums_size, int target, int* return_size) {
    int N_ELEMENTS = 2;

    *return_size = N_ELEMENTS;
    int* selected_indexes = (int*) malloc(N_ELEMENTS * sizeof(int));
    bool found_target = false;
    int sum;

    for (int i=0; i<nums_size-1; i++) {
        for (int j=i+1; j<nums_size; j++) {
            if (nums[i] + nums[j] == target) {
                found_target = true;
                selected_indexes[0] = i;
                selected_indexes[1] = j;
                break;
            }
        }
        if (found_target == true) break;
    }

    return selected_indexes;
}

int main() {
    int nums[] = {2, 15, 11, 7};
    int nums_size = 4;
    int target = 9;
    int return_size = -1;

    int* selected_indexes = twoSum(nums, nums_size, target, &return_size);
    printf("indexes: ");
    for (int i=0; i<return_size; i++) {
        printf("%d, ", selected_indexes[i]);
    }

    free(selected_indexes);
    return 0;
}
