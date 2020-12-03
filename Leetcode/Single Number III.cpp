class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(int n:nums){
            x ^= n;
        }
        int c=0,y=x;
        while(y){
            if(y&1){
                break;
            }
            c++;
            y>>=1;
        }
        int mask = (1<<c);
        y = 0;
        for(int n:nums){
            if(n&mask){
                y ^= n;
            }
        }
        return {y,y^x};
    }
};
