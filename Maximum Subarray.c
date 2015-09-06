int maxSubArray(int* nums, int numsSize) {
    int total=-32767;
    int sum=0;
    int i=0;
    for(;i<numsSize;i++)
    {
        if(sum<0)
            sum=0;
        sum+=nums[i];
        if(sum>total)
            total=sum;
    }
    return total;
}