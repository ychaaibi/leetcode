

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int j;
    int *Arr;
    
    Arr = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    i = 0;
    while (i < numsSize)
    {
        j = i + 1;
        while (j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                Arr[0] = i;
                Arr[1] = j;
                return (Arr);
            }
            j++;
        }
        i++;
    }
    return (Arr);
}