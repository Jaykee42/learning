/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target) {

    int *array = malloc(2*sizeof(int) );
    for (int i=0; i<numsSize;i++)
{
    for( int j=1+i;j<numsSize;j++)
    {
        if(nums[i] + nums[j] == target)
        {
        array[0]=i;
        array[1]=j;
        return array;
        }
    }   
    
}
return -1;

}

int main() {
    int cock[] = {2,7,11,15};
    int test = twoSum(cock, 4, 9);
    printf(test);
}