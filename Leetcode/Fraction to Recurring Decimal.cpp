class Solution {
        typedef long long ll;
    public:
        string fractionToDecimal(ll num, ll den) {
            string res = "";
            if(num == 0)return "0";
            if((num < 0) ^ (den < 0))res = "-";
            num = abs(num);
            den = abs(den);
            res += to_string(num / den);
            if(num % den == 0)return res;

            res += ".";
            unordered_map<ll, ll> mp;

            string s = "";
            ll r = num % den;
            ll i = 0;
            while(r) {
                if(mp.count(r)) {
                    s.insert(mp[r], "(");
                    s = s + ")";
                    break;
                }

                mp[r] = i;
                i++;

                r *= 10;
                s += to_string(r / den);
                r = r % den;
            }
            cout << res << " " << s;
            return res + s;
        }
};
