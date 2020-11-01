class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0,x = 1<<31;
        while(n){
            uint32_t r = n&1;
            ans += r*x;
            x>>=1;
            n>>=1;
        }
        return ans;
    }
};
