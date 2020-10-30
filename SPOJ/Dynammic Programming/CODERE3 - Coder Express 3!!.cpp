/*
CODERE3 - Coder Express 3!!
Mr Durgeshwara was very impressed by Rahul.But now he was in trouble.He has already fixed his daughter's marriage with Thangabali who was the best coder of his town. He got an idea and arranged a contest between Rahul and Thangabali.They have to solve a problem at the same time and whoever solves first will marry Meenamma. Rahul was not such a good coder and was also getting help from Meenamma.Your task is to help Thangabali to solve the problem to create a twist in story .

The problem was that there are large number of builing in the town which are of different heights and all the building are in a single line.
You have to find the maximum possible length of the subsequences of buildings which are possible which are first increasing in heights and then decreasing! Please Note: the heights of the building in the subsequences should be strictly increasing and then strictly decreasing

 

Input Specification:

First line contains an integer T( 1 < = T < = 100) that represents the number of test cases.Then follows the T containg the integer N(1 < = N < = 1000) specifying the total number of elements and the next line contains the N integers A1,A2,A3...An (1<= Ai< = 1000)

Output Specification:

For each test case, print only one line, the maximum length of such sequence.

Sample input:

2
10
1 3 5 6 4 8 4 3 2 1
6
8 6 3 4 2 1

Sample Output:

9
5

Explanation

for first test case the subsequence is : 1 3 5 6 8 4 3 2 1 for second case it is : 8 6 4 2 1


*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int maxBiotonicSubsequence(vector<int> a){
    int n = a.size();
    int inc[n] ;
    int dec[n] ;
    
    memset(inc,0,sizeof(inc));
    memset(dec,0,sizeof(dec));
    inc[0] = 1;
    dec[n-1] = 1;

    //int maxIncLength = -1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                int currentLength = 1 + inc[j];
                inc[i] = max(currentLength,inc[i]);
            }
        }
        if(inc[i] == 0){
            inc[i] = 1;
        }
        //maxIncLength = max(maxIncLength,inc[i]);
    }


    //int maxDecLength = -1;

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[j] < a[i]){
                int currentLength = 1 + dec[j];
                dec[i] = max(currentLength,dec[i]);
            }
        }
        if(dec[i] == 0){
            dec[i] = 1;
        }
        //maxDecLength = max(maxDecLength,dec[i]);
    }

    /*
    cout << "Inc - ";
    for(int i=0;i<n;i++){
        cout << inc[i] << " ";
    }
    cout <<"\nDec - ";
    for(int i=0;i<n;i++){
        cout << dec[i] << " ";
    }
    cout << endl; 
    */

    int maxLength = 0 ;
    for(int i=0;i<n;i++){
        int currentLength = inc[i] + dec[i] - 1 ;
        maxLength = max(maxLength,currentLength);
    }

    return maxLength ;
}


int main() {
    sync;
    int testCases;
    cin >> testCases;
    while(testCases--){
        int n ;
        cin >> n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        cout << maxBiotonicSubsequence(v) << endl;
    }
    
    
    
    return 0;
}

