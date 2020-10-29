#include <bits/stdc++.h>
using namespace std;

#define MAX 3000
int dp[MAX+1][MAX+1];

string getLCS(string& s,string& t,int len) {
    int i=0,j=0;
    string LCS;

    while(len>0) {
        if(s[i]==t[j]) {
            LCS.push_back(s[i]);
            i++;
            j++;
            len--;
        }
        else {
            if(dp[i][j+1] > dp[i+1][j]) {
                j++;
            } else {
                i++;
            }
        }
    }

    return LCS;
}

int lenOfLCS(string&s ,string& t,int i, int j) {
    if(i>=s.size() || j>= t.size()) {
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i]==t[j])
        return dp[i][j]=1+lenOfLCS(s,t,i+1,j+1);
    else 
        return dp[i][j]=max(lenOfLCS(s,t,i+1,j), lenOfLCS(s,t,i,j+1));
}

string printLCS(string& s,string& t) {
    int lcsLen = lenOfLCS(s,t,0,0);
    return getLCS(s,t,lcsLen);
}

string printLCSBottomUp(string a, string b) {
	int n = a.size(), m = b.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			// cout << dp[i][j] << " " ;
		}
		// cout << endl;
	}

	int length = dp[n][m];
	string ans = "";
	int i = n, j = m;
	while (length > 0) {
		if (a[i - 1] == b[j - 1]) {
			length--;
			ans = a[i - 1] + ans;
			i--; j--;
		} else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		} else {
			j--;
		}
	}
	return ans;
}

int main() {
    string s,t;
    cin >> s >> t;

    memset(dp,-1,sizeof dp);

    cout << printLCS(s,t) << "\n";

    return 0;
}
