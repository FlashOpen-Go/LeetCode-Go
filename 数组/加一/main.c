#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int* nums, int size);
int* plusOne(int* digits, int digitsSize, int* returnSize);

int main()
{
    int array[4] = {-1, -100, 3, 99};



    return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i = 0;
    for (i = digitsSize - 1; i >= 0; i--)
    {
        digits[i]++;
        if ((digits[i] % 10) == 0)
        {
            digits[i] = 0;
        }
        else
        {
            *returnSize = digitsSize;
            return digits;
        }        
    }
    int* ret = (int*)malloc(sizeof(int) * (digitsSize + 1));
    memset(ret, 0, (sizeof(int) * (digitsSize + 1));
    ret[0] = 1;
    *returnSize = digitsSize + 1;
    return ret;
}

void printArray(int* nums, int size)
{
    int i =0;
    for (i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}