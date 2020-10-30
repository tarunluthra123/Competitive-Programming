class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            int n = nums.size();
            if(n < 2)
                return 0;
            int maxElement = *max_element(nums.begin(), nums.end());
            int minElement = *min_element(nums.begin(), nums.end());

            double k = (maxElement - minElement) / (double)n;
            if(k == 0)
                return 0;

            vector<int> minInInterval(n, INT_MAX);
            vector<int> maxInInterval(n, INT_MIN);

            for(int val : nums) {
                size_t index = (val - minElement) / k;
                if(index == n)
                    index = n - 1;

                maxInInterval[index] = max(maxInInterval[index], val);
                minInInterval[index] = min(minInInterval[index], val);
            }

            int gap = 0;
            int prev = maxInInterval[0];

            for(int i = 0; i < n; i++) {
                if(minInInterval[i] == INT_MAX)continue;

                gap = max(gap, minInInterval[i] - prev);
                prev = maxInInterval[i];
            }

            return gap;
        }
};
