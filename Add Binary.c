void addtwobits(char *sum,char a,char b,int *carry)
{
    *sum=(((a-'0')+(b-'0')+*carry)&0x01)+'0';
    *carry=((a-'0')+(b-'0')+*carry)>>1;
}
void revert(char *a,int *len)
{
    int i=0;
    *len=strlen(a);
    for(i=0;i<(*len)/2;i++)
    {
        char tmp=a[i];
        a[i]=a[*len-1-i];
        a[*len-1-i]=tmp;
    }
}
char* addBinary(char* a, char* b) {
    int maxlen=0;
    int minlen=0;
    char* n;
    char* m;
    int ls,rs;
    revert(a,&ls);
    revert(b,&rs);
    if(ls>rs)
    {
        n=a;
        m=b;
        maxlen=ls+2;
        minlen=rs;
    }
    else
    {
        n=b;
        m=a;
        maxlen=rs+2;
        minlen=ls;
    }
    int i=0;
    int carry=0;
    char* sum=malloc(sizeof(char)*maxlen);
    for(;i<maxlen-2;i++)
    {
        if(i<minlen)
            addtwobits(&sum[i],n[i],m[i],&carry);
        else
            addtwobits(&sum[i],n[i],'0',&carry);
    }
    
    if(carry==1)
    {
        
        sum[i]=carry+'0';
        sum[i+1]=0;
    }
    else
        sum[i]=0;
    int len;
    revert(sum,&len);
    return sum;
}