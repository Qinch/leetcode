void revert(int *nums,int f,int l)
{
    int i=f;
    for(;i<=(f+l)/2;i++)
    {
        int tmp=nums[i];
        nums[i]=nums[l-(i-f)];
        nums[l-(i-f)]=tmp;
    }
}
void rotate(int nums[], int n, int k) {
        
        k=k%n;
        revert(nums,0,n-k-1);
        revert(nums,n-k,n-1); 
        revert(nums,0,n-1);
}