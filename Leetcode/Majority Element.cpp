class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int x=0,c;
        for(int n:nums){
            if(n==x){
                c++;
            }
            else{
                c--;
            }
            if(c<=0){
                x = n;
                c = 1;
            }
        }
        return x;
    }
};