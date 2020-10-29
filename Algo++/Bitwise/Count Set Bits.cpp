//count number of 1s in binary representation of an integer
//Input Format:
//Input N = Number of Test Cases, followed by N numbers
//Output Format:
//Number of Set Bits in each number each in a new line

#include <iostream>
using namespace std;
int main()
{
    int n,i,testCases;
    cin>>testCases;
    int c;
    while(testCases--)
    {
        c=0;
        cin>>n;
        i=0;
        while(n)
        {
            //cout<<"n="<<n<<"    iteration no.="<<i++<<endl;
            if(n&1==1)
            c++;
            n=n>>1;
        }
        cout<<c<<endl;
    }

    return 0;
}
