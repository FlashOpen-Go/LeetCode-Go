#include <stdio.h>
#include <stdlib.h>

void printArray(int* nums, int size);
int CmpInt(const void* a, const void* b);
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);


int main()
{
    int nums1[4] = {1,2,2,1};
    int nums2[2] = {2,2};

    int a;
    int *p = NULL;

    p = intersect(nums1, 4, nums2, 2, &a);

    printf("a = %d\n", a);

    printArray(p, a);

    free(p);

    return 0;
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
int CmpInt(const void* a, const void* b)
{
    return (*(int*)a > *(int*)b ? 1 : 0);
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
qsort(nums1, nums1Size, sizeof(nums1[0]), CmpInt);
    qsort(nums2, nums2Size, sizeof(nums1[0]), CmpInt);
    int min = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *array = (int*) malloc(sizeof(int) * (min));
    int k = 0, p = 0;
    for(int i = 0; i < nums1Size; i++)
    {
        for (int j = p; j < nums2Size; j++)
        {
            if ((nums1[i] == nums2[j]) && ( k < min))
            {
                array[k++] = nums1[i];
                p = j + 1;
                break;
            }
        }
    }
    *returnSize = k;
    return array;
}