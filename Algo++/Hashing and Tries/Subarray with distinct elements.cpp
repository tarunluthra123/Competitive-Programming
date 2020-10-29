/*
Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct


Input Format:
An integer n denoting size of array followed by n integers

Constraints:
1<=N<=10^5

Output Format:
The answer mod 10^9+7

Sample Input:
3
1 2 3
Sample Output:
10
Explanation:
{1, 2, 3} is a subarray of length 3 with distinct elements. 
Total length of length three = 3. {1, 2}, {2, 3} are 2 subarray of length 2 with distinct elements.
Total length of lengths two = 2 + 2 = 4 {1}, {2}, {3} are 3 subarrays of length 1 with distinct element.
Total lengths of length one = 1 + 1 + 1 = 3 Sum of lengths = 3 + 4 + 3 = 10
*/
#include <iostream>
#include <unordered_map>
#define modulo(a) a%1000000007
using namespace std;
int main() {
    long n;
    cin >> n;
    long a[n];
    for(long i=0;i<n;i++){
        cin >> a[i];
    }
    long size = 0 ;
    long sum = 0 ;
    for(long i=0;i<n;i++){
        unordered_map<long,int> m ; //New hashmap for each subarray
        long j;
        for(j=i;j<n;j++){
            //Start from i and keep inserting elements into hashmap till no repetition occurs
            if(m.find(a[j])==m.end()){
                //Insert into hashmap if unique element
                m[a[j]] = 1;
                sum += (j-i+1);
                //cout << "i="<<i<<"      j="<<j<<"       size="<<j-i+1<<"   sum="<<sum<<endl;
            }
            else {
                //Break the for loop otherwise
                break ;
            }         
        }
    }

    sum = modulo(sum) ;
    cout << sum ;


    return 0;
}

