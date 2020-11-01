class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)
            return {};
        unordered_set<string> seen,printed;
        for(int i=0;i<s.size()-9;i++){
            string t = s.substr(i,10);
            if(printed.find(t)!=printed.end())
                continue;
            if(seen.find(t)!=seen.end()){
                seen.erase(t);
                printed.insert(t);
            }
            else
                seen.insert(t);

        }
        vector<string> res(printed.begin(),printed.end());
        return res;
    }
};
