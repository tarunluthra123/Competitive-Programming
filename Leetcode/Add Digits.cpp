class Solution {
public:
    int addDigits(int num) {
        if(num<10)
            return num;
        int m = 0;
        while(num){
            m += num%10;
            num/=10;
        }
        return addDigits(m);
    }
};
