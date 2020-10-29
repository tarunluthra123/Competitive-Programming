class NumArray {
private:
    vector<int> pre;
public:
    NumArray(vector<int>& nums) {
        pre.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            pre[i] = i > 0 ? pre[i - 1] + nums[i] : nums[i];
        }
    }

    int sumRange(int i, int j) {
        int x = i > 0 ? pre[i - 1] : 0;
        int y = pre[j];
        return y - x;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */