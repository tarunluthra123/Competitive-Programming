/*
BOOK ALLOCATION PROBLEM
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.


Input Format:
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints:
1 < t < 50
1< n < 100
1< m <= 50

Output Format:
Print the maximum number of pages assigned to students. (see input and output format)

Sample Input:
1
4 2
12 34 67 90
Sample Output:
113 
Explanation:
1st students : 12 , 34, 67 (total = 113) 2nd students : 90 (total = 90) Print max(113, 90)
*/
#include <iostream>
using namespace std;
#define ll long long int

bool isValidConfig(ll *books,ll n,ll k,ll ans){
    ll students = 1;
    ll currentPages = 0;
    for(ll i=0;i<n;i++){
        if(currentPages + books[i] > ans){
            currentPages = books[i];
            students++ ;
            if(students > k){
                return false;
            }
        }
        else {
            currentPages += books[i];
        }
    }
    return true ;
}

ll bookAllocation(ll *books,ll n,ll k){
    ll totalPages = 0;
    ll s = 0 ;
    for(ll i=0;i<n;i++){
        totalPages += books[i];
        s = max(s,books[i]);
    }

    ll e = totalPages ;

    ll finalAns = s;

    while(s <= e){
        ll mid = (s+e)/2;
        if(isValidConfig(books,n,k,mid)){
            finalAns = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return finalAns;
}


int main() {
    int testCases;
    cin >> testCases;
    while(testCases--){
        ll n ;      //No of books
        cin >> n;
        ll m ;      //No of students
        cin >> m;
        ll a[n];

        for(ll i=0;i<n;i++){
            cin >> a[i];
        }

        cout << bookAllocation(a,n,m) << endl;
    }


    return 0;
}

