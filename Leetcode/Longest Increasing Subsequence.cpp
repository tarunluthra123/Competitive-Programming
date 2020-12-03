class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(x > v.back()){
                v.push_back(x);
            }
            else if(x < v[0]){
                v[0] = x;
            }
            else {
                int idx = lower_bound(v.begin(),v.end(),x) - v.begin();
                v[idx] = x;
            }
        }
        return v.size();
    }
};
