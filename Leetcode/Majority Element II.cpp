class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int one = 0, f1 = 0;
        int two = 0, f2 = 0;
        for(int x:nums){
            if(x == one){
                f1++;
            }
            else if(x == two){
                f2++;
            }
            else if(f1==0){
                one = x;
                f1 = 1;
            }
            else if(f2==0){
                two = x;
                f2 = 1;
            }
            else {
                f1--;
                f2--;
            }
        }

        f1 = 0;
        f2 = 0;
        for(int x:nums){
            if(one == x){
                f1++;
            }
            else if(two == x){
                f2++;
            }
        }

        vector<int> res;
        if(f1>nums.size()/3)
            res.push_back(one);
        if(f2>nums.size()/3)
            res.push_back(two);

        return res;
    }
};
