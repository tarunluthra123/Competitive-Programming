/*
ALL INDICES PROBLEM
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns an array containing indices of all items in the array which have value equal to M. Print all the values in the returned array.


Input Format:
Enter a number N(size of the array) and add N more numbers to the array Enter number M to be searched in the array

Constraints:
None

Output Format:
Display all the indices at which number M is found in a space separated manner

Sample Input:
5
3
2
1
2
3
2
Sample Output:
1 3
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> findIndex(vector<int> v,int i,int key,vector<int> ans) {
    //Base case
    if(i == v.size()) {
        //Traversed the entire array , return
        return ans ;
    }

    //Check if current index element matches key
    if(v[i] == key) {
        ans.push_back(i) ;
    }

    //Recursive call
    return findIndex(v,i+1,key,ans) ;
}

int main()
{
    vector<int> v;          //Input vector
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x ; 
        cin >> x;
        v.push_back(x);
    }

    int m;
    cin>>m;

    vector<int> ans;        //Vector to store the indices 
    ans = findIndex(v,0,m,ans);


    //Print the indices in the ans vector
    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

