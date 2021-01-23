#include <stdio.h>

int main()
{
    int a[1] = {1};

    int number = removeElement(a, 1, 1);

    printf("%d\n", number);
    int i = 0;
    for (i = 0 ; i < 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

int removeElement(int* nums, int numsSize, int val)
{
    if ((nums == NULL) || numsSize <= 0)
        return 0;
    
    int * p1 = nums;
    int * p2 = (nums + numsSize - 1);
    int count = 0;

    while (p1 <= p2)
    {
        if (*p2 == val)
        {
            p2 --;
            continue;
        }

        if (*p1 == val)
        {
            *p1++ = *p2;
            *p2-- = val;
            count++;
        }
        else
        {
            p1 ++;
            count++;
        }
        
    }
    
    return (count);

}