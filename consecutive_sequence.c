#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int longest = 1, curr = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) 
            continue;   
        else if (nums[i] == nums[i - 1] + 1) 
            curr++;
        else 
            curr = 1;

        if (curr > longest)
            longest = curr;
    }

    return longest;
}