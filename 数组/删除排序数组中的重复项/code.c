#include <stdio.h>

int main()
{
    return 0;
}

int removeDuplicates(int* nums, int numsSize)
{
    if (nums == NULL || numsSize <= 1)
        return numsSize;

    int count = 1;

    int temp = nums[0];

    for (int i = 1 ; i < numsSize; i++)
    {
        if (temp != nums[i])
        {
            nums[count++] = nums[i];
            temp = nums[i];
        }
    }
    return count;
}