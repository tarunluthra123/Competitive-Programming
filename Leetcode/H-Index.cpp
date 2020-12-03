class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n+1);
        for(int c : citations){
            if(c>=n){
                buckets[n]++;
            }
            else {
                buckets[c]++;
            }
        }

        int x = 0;
        for(int i=n;i>=0;i--){
            x += buckets[i];
            if(x>=i)
                return i;
        }
        return 0;
    }
};
