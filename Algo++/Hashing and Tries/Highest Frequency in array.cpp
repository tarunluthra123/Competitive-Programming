/*
Given an array find the number which comes with maximum frequency. It must work in O(n) time complexity.


Input Format:
Enter the size of the array N and add N more numbers and store in an array

Output Format:
Display the number with the maximum frequency.

Sample Input:
5
1
2
2
2
3
Sample Output:
2
Time Limit: 4 sec
*/
#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int,int> m; //Key,Freq pair
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        m[x]++;
    }
    int maxFreq = 0 ;
    int ans = 0;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second > maxFreq){
            maxFreq = it->second ;
            ans = it->first ;
        }
    }
    cout << ans ;
    
    
    
    
    return 0;
}

