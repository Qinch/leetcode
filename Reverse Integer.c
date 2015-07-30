int reverse(int x) {
    
    int ret=0;
    int flag=1;
    if(x<0)
        flag=-1;
    x=abs(x);
    while(x)
    {
        if(ret>((unsigned)((1<<31)-1))/10)
            return 0;
        int tmp=x%10;
        x=x/10;
        ret=ret*10+tmp;
    }
   
    return ret*flag;
}