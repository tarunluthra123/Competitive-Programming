/*
FIND THE GREATER ELEMENT
We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + i and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.


Input Format:
First line contains the length of the array n. Second line contains the n space separated integers.

Output Format:
Print n space separated integers each representing the next greater element.

Sample Input:
3
1 2 3
Sample Output:
2 3 -1
Explanation:
Next greater element for 1 is 2, for 2 is 3 but not present for 3 therefore -1

*/



#include <iostream>
using namespace std;
int findLargest(int a[],int n,int p){
    for(int i=p+1;i!=p;i++){
        if(i==n)
            i = 0;
        if(a[i]>a[p]){
            return a[i];
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a[1000];
    cin>>n;
    int m = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m = max(a[i],m);
    }
    for(int i=0;i<n;i++){
        if(a[i]==m){
            cout<<"-1 ";
            continue;
        }
        cout<<findLargest(a,n,i)<<" ";
    }

    return 0;
}

