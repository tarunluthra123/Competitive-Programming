//Constructing Prime Sieve

#include <iostream>
using namespace std;
const long n=5000000;
void primes(long *p)
{
    for(long i=3;i<n;i++)
         p[i]=i&1?1:0;
    for(long i=3;i<=n;i+=2)
    {
        if(p[i])
        {
            for(long j=i*i;j<n;j+=i)
                p[j]=0;
        }
    }
    p[2]=1;
    p[1]=0;
    p[0]=0;
}
int main() 
{   
    long sieve[n]={0};
    long i,j;
   
    primes(sieve);
    
    return 0;
}

