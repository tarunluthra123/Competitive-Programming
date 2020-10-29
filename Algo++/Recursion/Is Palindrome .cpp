/*
IS PALINDROME?
Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.


Input Format:
Enter a number N , add N more numbers

Constraints:
None

Output Format:
Display the Boolean result

Sample Input:
4
1
2
2
1
Sample Output:
true
*/
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(vector<int> v,int s,int e){
    if(s >= e){
        return true ;
    }
    if(v[s] != v[e]){
        return false ;
    }

    return isPalindrome(v,s+1,e-1);
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }


    cout << boolalpha << isPalindrome(v,0,v.size()-1);

    return 0;
}

