bool ispowerof2(int num){
    return !(num & num-1);
}
 
//code to find number of one's in binary representation of a number;
int num_of_ones(int num){
    int count = 0;
    while(num){
        count++;
        num &= num-1;
    }
    return count;
}
 
//program to find left most set bit i.e most significant bit;
//idea is keep dividing till number becomes zero;
int msb(int num){
    int count = 0;
    while(num){
        num /=2;
        count+=1;
    }
    return count;
}
 
//O(1) method to find most significant bit;
int msb_(int num){
    return log2(num) + 1;
}
 
//program to find right most bit i.e least significant bit;
int lsb(int num){
    return num & -num;
}



//generating subsets 

long filterInts(long a[],long n)
{
    long s=0,i=0;
    while(n)
    {
        if(n&1)
        s=s+a[i];
        i++;
        n=n>>1;
    }
    return s;
}

bool findSum(long a[],long size,long s)
{
    long value;
    long range=(1<<size)-1;
    for(long i=0;i<range;i++)
    {
        value=filterInts(a,i);
        if(value==s)
        return true;
    }
    return false;
}






// empty main
int main()
{
	return 0;
}