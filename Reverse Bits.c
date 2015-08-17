
uint32_t reverseBits(uint32_t n) {
    int i=0;
    uint32_t ret=0;
    for(;i<32;i++)
    {
        ret=(ret<<1);
        if((n&0x01)==0x01)
        {
            ret=ret+1;
        }
        n=n>>1;
    }
    return ret;
}