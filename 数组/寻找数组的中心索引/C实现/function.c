int pivotIndex(int* nums, int numsSize){
    if (numsSize <= 0)
        return -1;
    int i = 0;
    int sum = 0;
    int temp_sum = 0;
    int temp_sum_2 = 0;
    for (i = 0; i < numsSize; i++)
        sum += nums[i];
    temp_sum = 0;
    for (i = 0; i < numsSize; i++)
    {
        // if (temp_sum * 2 == (sum - nums[i]))
        if (temp_sum == (sum - nums[i] - temp_sum))
        {
            return i;
        }
        temp_sum += nums[i];
    }
    return -1;
}