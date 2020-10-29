#include <bits/stdc++.h>
using namespace std;

class Compare {
public:
	bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
		if(a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}
};

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
    	int n,k;
    	cin >> n >> k;
    	unordered_map<int,int> mp;	//Storing as <num,freq>
    	set < pair<int,int> , Compare > s;	//Storing as <freq,num>
    	for (int i = 0; i < n; ++i) {
    		int x;
    		cin >> x;
    		pair<int,int> temp;
    		if(mp.find(x) != mp.end()) {
    			temp = make_pair(mp[x],x);
    			s.erase(temp);
    			mp[x]++;
    			temp.first = mp[x];
    			s.insert(temp);
    			// cout << "rep";
    		}
    		else {
    			mp[x] = 1;
    			temp = make_pair(1, x);
    			s.insert(temp);
    		}

    		int c = 0;
    		for(auto it=s.begin() ; it!=s.end() && c<k ; it++, c++) {
    			cout <<  it->second << " " ;
    		}
    		// cout << endl;
    	}
    	cout << endl;
    }

    return 0;
}
