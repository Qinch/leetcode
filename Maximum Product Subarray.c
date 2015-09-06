int maxProduct(int* nums, int numsSize) {
    int total=-32767;
    int sum=1;
    int i;
    for(i=0;i<numsSize;i++)
    {
        sum*=nums[i];
        if(sum>total)
            total=sum;
        if(sum==0)
            sum=1;
    }
    sum=1;
    for(i=numsSize-1;i>=0;i--)
    {
        sum*=nums[i];
        if(sum>total)
            total=sum;
        if(sum==0)
            sum=1;
    }
    return total;
}