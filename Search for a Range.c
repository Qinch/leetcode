/**
 * Return an array of size: *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numSize, int target, int* returnSize) {
    *returnSize=2;
    int* ret=(int*)malloc(sizeof(int)*2);
    ret[0]=ret[1]=-1;
    int i=0;
    int j=numSize-1;
    int hit=-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(nums[j]<target)
            break;
        if(nums[mid]>=target)
        {
            if(nums[mid]==target)
                hit=mid;
            j=mid-1;
        }
        else 
            i=mid+1;
    }

    if(hit==-1)
        return ret;
    else 
        ret[0]=hit;
    
    i=hit;
    j=numSize-1;
    hit=-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(nums[i]>target)
            break;
        if(nums[mid]>target)
            j=mid-1;
        else 
        {
            if(nums[mid]==target)
                hit=mid;
            i=mid+1;
        }
    }
    if(hit==-1)
        return ret;
    else
        ret[1]=hit;
    return ret;
}