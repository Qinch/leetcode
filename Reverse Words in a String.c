void reverse(char *h,char *t)
{
    while(h<t)
    {
        char temp=*h;
        *h=*t;
        *t=temp;
        h++;
        t--;
    }
}

void trim(char *s)
{
    int i=0;
    int j=0;
    int flag=1;
    while(s[j])
    { 
        if( (s[j]!=' ')&&(s[j]!='\t') )
        {
            s[i++]=s[j++];
            flag=0;
        }
        else
        {
            if(flag==0)
            {
                s[i++]=' ';
                flag=1;
            }
            else
                j++;
        }
    }
    if(s[i-1]==' ')
        s[i-1]='\0';
    else
        s[i]='\0';
}

void reverseWords(char *s) {
    trim(s);
    printf("/%s/\n",s);
    int p=0;
    int q=0;
    int i=0;
    while(s[i])
    {
        if(s[i]==' ')
        {
            q=i-1;
            reverse(s+p,s+q);
            p=i+1;//ÏÂÒ»¸öword;
        }
        i++;
    }
    printf("%d %d\n",p,i);
    reverse(s+p,s+i-1);
    reverse(s,s+i-1); 
}