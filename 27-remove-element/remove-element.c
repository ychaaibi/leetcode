void swap(int *nums, int numsSize, int i)
{
    while (i < numsSize - 1)
    {
        nums[i] = nums[i + 1];
        i++;
    }
}

int removeElement(int* nums, int numsSize, int val){
    int i;
    
    i = 0;
    while (i < numsSize)
    {
        if (nums[i] == val)
        {
            swap(nums, numsSize, i);
            numsSize--;
            i = -1;
        }
        i++;
    }
    return (numsSize);
}
