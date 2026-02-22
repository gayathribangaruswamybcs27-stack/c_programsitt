int rob(int* nums, int numsSize) 
{
    if(numsSize == 1) return nums[0];
    int prev2 = 0;   
    int prev1 = 0;   
    for(int i = 0; i < numsSize; i++)
    {
        int curr = (prev1 > nums[i] + prev2) ? prev1 : nums[i] + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}