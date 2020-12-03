#define ll long long
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, ll k, ll t) {
        int n = nums.size();
        unordered_map<ll,ll> buckets;
        if (t < 0)
            return false;
        for(ll i=0;i<n;i++){
            ll idx = (ll)nums[i] /(t+1);
            if(nums[i] < 0)
                --idx;
            if(buckets.count(idx)){
                return true;
            }
            else if(buckets.count(idx-1) and abs(buckets[idx-1] - nums[i]) <= t){
                return true;
            }
            else if(buckets.count(idx+1) and abs(buckets[idx+1] - nums[i]) <= t){
                return true;
            }
            else {
                buckets[idx] = (ll)nums[i];
            }
            if(i>=k){
                buckets.erase((ll)nums[i - k] / (t+1));
            }
        }

        return false;
    }
};
