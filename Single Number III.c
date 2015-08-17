/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int testbits(unsigned int tmp)
 {
     int i=0;
     while((tmp&01)==0x00)//注意优先级;
     {
         
        tmp=tmp>>1;
        i++;
     }
     
     return i;
 }
 int testnbit(unsigned int tmp,int n)
 {
     while(n--)
     {
         tmp=tmp>>1;
     }
     if(tmp&0x01==0x01)
        return 1;
    else
        return 0;
        
 }
int* singleNumber(int* nums, int numSize, int* returnSize) {
    int i=0;
    int tmp=0;
    for(;i<numSize;i++)
    {
        tmp=tmp^nums[i];
    }
   
    int n=testbits(tmp);
     
    int lhs=0;
    int rhs=0;
    for(i=0;i<numSize;i++)
    {
        if(testnbit(nums[i],n))
            lhs=lhs^nums[i];
        else
            rhs=rhs^nums[i];
    }
    int *arr=malloc(sizeof(int)*2);
    arr[0]=lhs;
    arr[1]=rhs;
    *returnSize=2;
    return arr;
}