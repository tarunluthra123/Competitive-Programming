class Solution {
public:
    int titleToNumber(string s) {
        return s.size()==0? 0 : (s[0]-'A'+1)*pow(26,s.size()-1)+titleToNumber(s.substr(1));
    }
};
