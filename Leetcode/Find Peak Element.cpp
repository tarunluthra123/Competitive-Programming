class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > nums[(i-1+n)%n] and nums[i] > nums[(i+1)%n]){
                return i;
            }
        }
        return 0;
    }
};
