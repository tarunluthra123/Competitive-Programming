//LCM and GCD using Eculidean Algorithm

#include <iostream>
using namespace std;
long gcd(int a,int b)
{
    if(b==0)
    return a;

    return gcd(b,a%b);
}

int main() 
{
    long a,b,lcm,hcf;
    cin>>a>>b;
    hcf=gcd(a,b);
    lcm=(a*b)/hcf;
    cout<<lcm;

    return 0;
}

