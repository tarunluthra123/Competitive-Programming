/*
1 COUNT
Given an array of size n with 0s and 1s , flip at most k 0s to get the longest possible subarray of 1s.


Input Format:
First Line : n, size of array and k Second Line : n space separated numbers (0s or 1s)

Constraints:
n <= 10^5
0 <= k <= n

Output Format:
First Line : Size of subarray Second Line : Array after flipping k 0s

Sample Input:
10 2
1 0 0 1 0 1 0 1 0 1
Sample Output:
5
1 0 0 1 1 1 1 1 0 1
Time Limit: 1 sec
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void flipCount(vector<int> a,lli k){
    
    if(k == 0){
        //Simply count the max subarray of 1's
        pair<lli,lli> p;
        lli ans = 0 ;
        for(lli i=0;i<a.size()-1;i++){
            if(a[i] == 1){
                lli j;
                for(j=i+1;j<a.size() && a[j]==1;j++){}
              //  cout << "i = "<< i << "     j="<< j <<endl;
                if(ans < j-i){
                    ans = j-i;
                    p.first = i;
                    p.second = j;
                }
            }
        }
        cout << ans << endl; 
        for(lli i=0;i<a.size();i++){
            if(i>=p.first && i<p.second){
                cout << "1 ";
            }
            else {
                cout << a[i] << " ";
            }
        }
        return ;
    }

    lli c = 0 ,j;
    
    for(j=0;c<k;j++){
       // cout << "a["<<j<<"] = "<< a[j] <<" c= "<<c<<endl;
        if(a[j]==0){
            c++;
        }
        if(c == k)  break;
    }
    
    //cout << "j = "<< j << endl;
    lli i = 0 ;
    lli maxLength = 0 ;

    pair<lli,lli> p ;           //For storing the indices of best i and j
    while(i<j && j<a.size()){

        //Move j ahead if following integer is a 1 as it does not need to be flipped 
        while(a[j+1] == 1 && j<a.size()-1){
            j++;
        }

        //Get the current length of 1's
        lli currentLength = j - i + 1;

       // cout << "cl = "<<currentLength << "     ml = "<<maxLength <<"   i="<<i<<"       j="<<j<<endl;
        if(currentLength > maxLength){
            //If currentLength is greater , update maxLength and store values of i and j in the pair
            maxLength = currentLength;
            p.first = i;
            p.second = j;
        }

        i++;    //Move i pointer ahead by one 

        //Since we moved i from a 0 bit , we can increase j by one to maintain the window for max no of flips
        if(a[i-1] == 0){
            j++;
        }
        
    }


    cout << maxLength << endl; 
   // cout << p.first << "    " << p.second <<endl;
    for(lli i=0;i<a.size();i++){
        if(i>=p.first && i<=p.second){
            cout << "1 ";
        }
        else {
            cout << a[i] << " ";
        }
    }
}





int main() {
    lli n,k;
    cin >> n >> k;
    vector<int> a;
    for(lli i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    

    flipCount(a,k) ;



    return 0;
}

