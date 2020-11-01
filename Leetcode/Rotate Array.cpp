class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        auto it=nums.begin();
        while(k--)it++;
        reverse(nums.begin(),nums.end());
        reverse(it,nums.end());
        reverse(nums.begin(),it);
    }
};
