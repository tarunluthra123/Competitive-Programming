#include<iostream>
#include<cstring>
using namespace std;

void permute(string inp, string out) {
    if(inp.length() == 0) {
        cout << out << endl;
        return ;
    }

    for (int i = 0; i < inp.length(); ++i) {
        string ros = inp.substr(0,i) + inp.substr(i+1);
        permute(ros, out + inp[i]);
    }
}

int main() {
    string inp;
    cin >> inp;

    permute(inp,"");

    return 0;
}

