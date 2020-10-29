/*
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Return the minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer, representing the answer as described in the problem statement.
Constraints:

1 <= N <= 1e6
0 <= A[i] <= 50000
Examples:

Input 1:
    A = [2, 1, 1]

Output 1:
    1
    
Explanation 1:
    The shortest way to reach index 2 is
        Index 0 -> Index 2
    that requires only 1 jump.

Input 2:
    A = [2,3,1,1,4]

Output 2:
    2

Explanation 2:
    The shortest way to reach index 4 is
        Index 0 -> Index 1 -> Index 4
    that requires 2 jumps.
*/
int minJumps(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return 0;

    if (arr[0] == 0)
        return -1;

    // initialization
    int maxReach = arr[0]; // stores all time the maximal reachable index in the array.
    int step = arr[0];     // stores the number of steps we can still take
    int jump = 1;          //stores the number of jumps necessary to reach that maximal reachable position.

    int i = 1;
    for (i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;

        maxReach = max(maxReach, i + arr[i]);

        step--;

        if (step == 0)
        {
            jump++;

            if (i >= maxReach)
                return -1;

            step = maxReach - i;
        }
    }

    return -1;
}

int Solution::jump(vector<int> &A) {
    int ans = minJumps(A);
    // if(ans == INT_MAX) 
        // return -1;
        
    return ans;
}

