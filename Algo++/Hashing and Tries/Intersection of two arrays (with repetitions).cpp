/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take N more inputs and store that in another array. Write a function which gives the intersection of two arrays in an ArrayList of integers and Print the ArrayList.


Constraints:
Length of Arrays should be between 1 to 1000.

Sample Input:
7
1 2 3 1 2 4 1
2 1 3 1 5 2 2
Sample Output:
[1, 1, 2, 2, 3]
Explanation:
Check which integer is present in both the arrays and add them in an Arraylist .Print ArrayList as the ans.
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<int,int> m;    // <Number,Frequency> pair
    int n ;
    cin >> n;
    int temp ;
    for(int i=0;i<n;i++){
        cin >> temp ;
        if(m.find(temp)==m.end()){
            //Does not exist , create new entry
            m.insert(make_pair(temp,1));
        }
        else {
            //Key already exists .. increment the frequency
            m[temp]++;
        }
    }

    vector<int> ans ; 
    for(int i=0;i<n;i++){
        cin >> temp ; 
        if(m.find(temp)!=m.end() && m[temp]>0){
            m[temp]--;      //Decrement frequency to ensure it is not repeated
            ans.push_back(temp);
        }
    }

    sort(ans.begin(),ans.end());

    cout << "[";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] ;
        if(i < ans.size()-1)
            cout << ", ";
    }
    cout << "]";


    return 0;
}

