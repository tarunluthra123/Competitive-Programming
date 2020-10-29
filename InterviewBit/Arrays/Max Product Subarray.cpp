/*
https://www.interviewbit.com/problems/max-product-subarray/
Max Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
*/
int Solution::maxProduct(const vector<int> &nums) {
    int ans = 1;
        int maxSoFar = 1;
        int minSoFar = 1;
        int maxElement = INT_MIN;
        bool flag = false;
        int arrProduct = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                maxSoFar = minSoFar = 1;
            }
            else if(nums[i] > 0) {
                flag = true;
                maxSoFar *= nums[i];
                minSoFar *= nums[i];
                minSoFar = min(minSoFar ,1);
            }
            else {
                maxSoFar *= nums[i];
                minSoFar *= nums[i];
                swap(maxSoFar, minSoFar);
                maxSoFar = max(maxSoFar, 1);
            }

            ans = max(maxSoFar, ans);
            maxElement = max(maxElement, nums[i]);
            arrProduct *= nums[i];
        }

        if(!flag && ans==1 && maxSoFar==1)
            return max(maxElement, arrProduct);
        return ans;
}

