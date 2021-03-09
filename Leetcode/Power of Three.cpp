class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = log10(n)/log10(3.0);
        return x == round(x) and n>0;
    }
};
