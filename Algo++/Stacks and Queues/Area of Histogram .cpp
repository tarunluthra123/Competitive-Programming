/*
HISTOGRAM
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.


Input Format:
First line contains a single integer N, denoting the number of bars in th histogram. Next line contains N integers, ith of which, denotes the height of ith bar in the histogram.

Constraints:
1<=N<=10^6 Height of each bar in histogram <= 10^9

Output Format
Output a single integer denoting the area of the required rectangle.

Sample Input
5
1 2 3 4 5
Sample Output
9s
*/
#include <iostream>
#include <stack>
using namespace std;
long maxHistogramArea(long a[],long n){
    stack<long> s;
    long maxArea = 0;
    for(long i=0;i<n;i++){
        if(s.empty()){
            s.push(i);
        }
        else {
            if(a[i]<a[s.top()]){
                while(!s.empty() && a[i]<a[s.top()]){
                    long x = s.top();
                    s.pop();
                    long area = 0;
                    if(s.empty())
                        area = a[x] * i ;
                    else 
                        area = a[x] *(i - s.top() - 1);
                    //cout<<"popping "<<x<<"  area = "<<area<<"   i = "<<i<<endl;
                    maxArea = max(area,maxArea);
                }
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        long area = 0;
        long x = s.top(); 
        s.pop();
        if(s.empty()){
            area = a[x] * n ;
        }
        else {
            area = a[x] *(n - x );
        }
        //cout<<"popping "<<x<<"  area = "<<area<<"   i = "<<n<<endl;
         //   area = a[s.top()] *(s.top() - s.top() - 1);
        maxArea = max(area,maxArea);
    }
    return maxArea;
}
int main() {
    long a[100000];
    long n ;
    cin>>n;
    for(long i=0;i<n;i++){
        cin>>a[i];
    }
    long ans = maxHistogramArea(a,n);
    cout<<ans;
    return 0;
}

