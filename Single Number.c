int singleNumber(int* nums, int numsSize) {
    
    int i=0;
    int ret=0;
    for(i=0;i<numsSize;i++)
    {
        ret=ret^nums[i];
    }
    return ret;
}