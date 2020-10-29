/*
Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

 

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]
Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]
 

Note:

1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(A.begin(), A.end());
        int n = A.size();
        // for (int i = 0; i < n; ++i) {
        //     s.insert(A[i]);
        // }

        vector<int> ans(n);

        for(int i=0;i<n;i++)  {
            int b = B[i];
            auto it = s.upper_bound(b);
            if(it == s.end()) {
                //Not found
                //Use the otherwise useless element i.e. the first element
                ans[i] = *(s.begin());
                s.erase(s.begin());
            }
            else {
                ans[i] = *it;
                s.erase(it);
            }
        }

        return ans;
    }
};
