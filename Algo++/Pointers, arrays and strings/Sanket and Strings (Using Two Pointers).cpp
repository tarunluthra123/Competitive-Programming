/*
SANKET AND STRINGS
Sanket has a string consisting of only a and b as the characters. Sanket describes perfectness of a string as the maximum length substring of equal characters. Sanket is given a number K which denotes the maximum number of characters he can change. Find the maximum perfectness he can generate by changing no more than k characters


Input Format:
The first line contains an integer denoting the value of K. The next line contains a string having on ‘a’ and ‘b’ as the characters

Constraints:
2 = N = 10^5

Output Format:
Single integer denoting the maximum perfectness achievable

Sample Input:
2
abba
Sample Output:
4
Time Limit: 2 sec
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
    lli k ;
    cin >> k;
    string s ;
    cin >> s;

    if(k>=s.size()){
        cout << s.size() ;
        return 0;
    }

    //First let us check for longest perfect string of A's then we will find the same for B's and compare

    lli i = 0;
    lli j = 0 ;
    lli c = 0 ;
    lli ansForA = 0 ;
    for(j ; c < k && j<s.size()-1 ;j++){
        if(s[j]=='b'){
            c++;
        }
        if(c == k){
            break;
        }
    }
    //cout << j ; 

    while(i<j){

        //Move j ahead if next element is a
        while(j<s.size()-1 && s[j+1] == 'a') {
            j++;
        }

        lli currentLength = j - i + 1;
        ansForA = max(ansForA,currentLength);

        i++;

        if(j<s.size()-1 &&  s[i-1] == 'b'){
            j++;
        }

    }
    
   // cout << "Max length of perfect string with A = "<<ansForA<<endl;



    //Now we do the same for B's
    i = 0 ;
    j = 0 ;
    c = 0 ;
    lli ansForB = 0;

    for(j ; c < k  && j<s.size()-1;j++){
        if(s[j]=='a'){
            c++;
        }
        if(c == k){
            break;
        }
    }

    while(i<j){

        //Move j ahead if next element is b
        while(j<s.size()-1 && s[j+1] == 'b') {
            j++;
        }

        lli currentLength = j - i + 1;
        ansForB = max(ansForB,currentLength);

        i++;

        if(j<s.size()-1 && s[i-1] == 'a'){
            j++;
        }

    }
    
     //cout << "Max length of perfect string with B = "<<ansForB<<endl;

    cout << max(ansForA,ansForB);


    return 0;
}

