/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/sumit-and-chocolates-c9e3069d/

Sumit's love for Pokemons
Sumit is very fond of Pokemons and spend all his pocket money buying pokemon cards only. One day, his friend Himanshu introduced him to a game called 'Pokeball', where participants can win a large number of pokemon cards.

'Pokeball' is a game in which you are given a string consisting of English letters (both upper case and lower case). Each of these letters corresponds to a unique pokemon cards. Now as usual there are some rules in the game.

A participant can change one of the letters in the sequence and make it to represent other type of pokemon cards. This move is called a Kalti move. Each game has some fixed number of Kalti moves allowed. You need to find ‘L’ i.e. the maximum length of consecutive characters of the string where all letters denotes the same pokemon cards using at most ‘k’ Kalti moves. If your answer is right then you will get ‘L’ no. of pokemon cards as reward. Upper case and lower case letters represent different type of Pokemon Cards. Since; Sumit is busy watching ‘Game of Thrones’, Can you solve this problem for him?

Note: 'A' and 'a' represents different Pokemon Cards.

Input: First line contain T, number of test cases.

The first line of the test case contains two integers n and k (1?=?n?=?100?000,?0?=?k?=?n) — the length of the string and the maximum number of Kalti Moves.

The second line of the test case contains the string, consisting of lower case letters and upper case letters only.

Output: For each test case output one new line containing the required output ‘L’ i.e. the maximum no. of pokemon cards Sumit can win.

Constraint:

1=?T=?12
1?=?n?=?100?000
0?=?k?=?n
String will be made up of lower case and upper case letters only.
Scoring :

40 points (String is made up of letters 'a' and 'b' only).
60 points : Original constraint
SAMPLE INPUT 
2
4 1
aaab
6 2
bbaaba
SAMPLE OUTPUT 
4
5
Explanation
In first test case, we can get string aaaa by changing last letter b with a .

In the second case, we can change the string to get bbbbba.

*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

ll longestSubstringWithKSwaps(string &s,ll k,char ch) {
    ll i = 0 ;
    ll j = 0 ;
    ll c = 0 ;
    ll ans = 0;

    if(k == 0) {
        //Just find the longest substring with ch
        for(i=0;i<s.size();i++) {
            for(j=i;j<s.size() && s[j]==ch ; j++) ;
            ll currentLength = j - i ;
            ans = max(currentLength,ans);
        }

        return ans;
    }

    for(j ; c < k  && j<s.size()-1;j++){
        if(s[j]!=ch){
            c++;
        }
        if(c == k){
            break;
        }
    }

    //cout << "j = " << j << endl;

    while(i<=j && i<s.size()){

        //Move j ahead if next element is ch
        while(j<s.size()-1 && s[j+1] == ch) {
            j++;
        }

        ll currentLength = j - i + 1;
        ans = max(ans,currentLength);

        i++;

        if(j<s.size()-1 && s[i-1] != ch){
            j++;
        }

        if(i < s.size() && i==j) {
            i++;j++;
        }
    }

    return ans;
}




int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll finalAns = 0;
        //cout << longestSubstringWithKSwaps(s,k,'a') << endl;
        
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            finalAns = max(finalAns,longestSubstringWithKSwaps(s,k,ch)) ;
        }
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            finalAns = max(finalAns,longestSubstringWithKSwaps(s,k,ch)) ;
        }
        
        cout << finalAns << endl;
    }
    return 0;
}

