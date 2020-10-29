/*
There is a class consisting of 'N' students . There can be many students with the same name.

Now, you have to print the names of the students followed by there frequency as shown in the sample explanation given below.

Output the names in the lexicographical order.

Input :

First line contains an integer 'N', i.e the no. of students in the class.
Next 'N' lines contains the names of the students.
Output:

Each line consists of the name of student space and separated its frequency.
Constraints:

1<=N<=1000
string length<=100
string consists of lowercase letters
Note : For practicing use Map technique only .

SAMPLE INPUT 
5
sumit
ambuj
himanshu
ambuj
ambuj
SAMPLE OUTPUT 
ambuj 3
himanshu 1
sumit 1
*/
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main() {
    map<string,int> m;
    int n;
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        if(m.find(s)==m.end()){
            //Create new entry
            m[s] = 1;
        }
        else {
            //Update the frequency
            m[s]++;
        }
    }
    for(auto it=m.begin();it!=m.end();it++){
        cout << it->first << " " << it->second << endl ;
    }

    return 0;
}

