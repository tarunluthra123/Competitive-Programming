class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m,p;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])){
                char u = m[s[i]];
                if(u!=t[i])return false;
            }
            if(p.count(t[i])){
                char q = p[t[i]];
                if(q!=s[i])return false;
            }
            m[s[i]] = t[i];
            p[t[i]] = s[i];
        }
        return true;
    }
};
