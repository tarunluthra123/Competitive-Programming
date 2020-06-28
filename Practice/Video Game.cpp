#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,h;
    cin>>n>>h;
    vector<int> box(n);
    for (int i = 0; i < n; ++i) {
    	cin>>box[i];
    }

    int pos=0;
    bool hold=false;

    int q;
    cin>>q;
    while(q>0){
    	if(q==1){
    		pos=max(0,pos-1);
    	}
    	else if(q==2){
    		pos=min(n-1,pos+1);
    	}
    	else if(q==3){
    		if(!hold and box[pos]){
    			box[pos]--;
    			hold=true;
    		}
    	}
    	else if(q==4){
    		if(hold && box[pos]+1<=h){
    			hold=false;
    			box[pos]++;
    		}
    	}


    	cin>>q;
    }

    for (int i = 0; i < n; ++i) {
    	cout<<box[i]<<" " ;
    }

    return 0;
}
