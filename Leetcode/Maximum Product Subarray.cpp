//https://leetcode.com/problems/maximum-product-subarray/submissions/
/*
152. Maximum Product Subarray
Medium

2915

126

Add to List

Share
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
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
};
