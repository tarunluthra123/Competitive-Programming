/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/#

Repeat and Missing Number Array
Asked in:  
Amazon
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ans ;
    int x = 0;
    for(int i=0;i<A.size();i++){
        x = x^A[i];
        x = x^(i+1);
    }
    int rightMost = 0 ; 
    int y = x;
    while(y) {
        if(y&1){
            break;
        }
        rightMost++;
        y = y>>1;
    }
    int mask = (1<<rightMost);
    int a = 0;
    int b = 0;
    for(int i=0;i<A.size();i++) {
        if(mask&A[i]) {
            a = a^A[i];
        }
        if(mask&(i+1)){
            b = b^(i+1);
        }
    }
    int res1 = a^b ; 
    int res2 = x^res1;
    vector<int> res;
    int i;
    for(i=0;i<A.size();i++) {
        if(A[i]==res1) {
            break;
        }
    }
    if(i==A.size()) {
        res.push_back(res2);
        res.push_back(res1);
    }
    else {
        res.push_back(res1);
        res.push_back(res2);
    }
    return res;
}

