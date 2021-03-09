class Solution {
public:
    bool isPowerOfFour(int n) {
        double x = log10(n)/log10(4.0);
        return x == round(x) and n>0;
    }
};
