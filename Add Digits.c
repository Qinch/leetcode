int addDigits(int num) {
    if(num<10)
        return num;
    int sum;
    while(num>=10)
    {
        sum=0;
        while(num!=0)
        {
            sum+=num%10;
            num=num/10;
        }
        num=sum;
    }
    return num;
}