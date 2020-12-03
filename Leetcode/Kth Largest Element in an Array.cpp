class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        k = nums.size() - k + 1;
        for(int x:nums){
            if(pq.size() < k){
                pq.push(x);
            }
            else {
                if(x < pq.top()){
                    pq.pop();
                    pq.push(x);
                }
            }
        }
        return pq.top();
    }
};
