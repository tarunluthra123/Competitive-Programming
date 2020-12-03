class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            if(s.find(n)!=s.end())return false;
            s.insert(n);
            int m = 0;
            while(n){
                int r = n%10;
                n/=10;
                m += r*r;
            }
            n = m;
        }
        return true;
    }
};
