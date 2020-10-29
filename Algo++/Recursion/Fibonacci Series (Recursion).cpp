/* Program for generating Fibonacci series upto n terms using recursion
   Created by Tarun Luthra
   Roll No. = 2018 CSC 1023   																	*/
   
#include <iostream>

typedef long long ll;   //long long used as fibonacci series grows very fast

using namespace std;

ll fibonacci(ll n)  //prints Fibonacci series upto n terms
{
    if(n<=1)    //0th term is 0 , 1st term is 1
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    ll n,i;
    cout<<"Fibonacci Series \n";
    cout<<"Enter no of terms to print = ";
    cin>>n;
    for(i=0;i<n;i++)
    {
         cout<<fibonacci(i);
         if(i<n-1)		//to prevent comma after the last term
         cout<<", ";
    }
    return 0;
}
