// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low=1;
    int high=n;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(!isBadVersion(mid))//�������bug�汾;
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}