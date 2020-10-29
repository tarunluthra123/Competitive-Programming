/*
STRING WINDOW
Ravi has been given two strings named string1 and string 2. He is supposed to find the minimum length substring of the string1 which contains all the characters of string2. Help him to find the substring


Input Format:
The first line of the input contains string1. String1 can be a string containing spaces also. The second line of the input contains string2. String2 can be a string containing spaces also.

Constraints:
Length of both the strings can be at max 10^4

Output Format:
Output the substring in a single line. If no such substring exist then output "No string" without quotes

Sample Input:
qwerty asdfgh qazxsw
qas
Sample Output:
qazxs
Time Limit: 1 sec
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	string A,B;
	getline(cin,A);
	getline(cin,B);
	unordered_map<char,int> Bmap;
	for(int i=0;i<B.size();i++){
        //Insert all elements of B into hashmap with frequency of each character
	    Bmap[B[i]]++;
    }

	unordered_map<char,int> Amap;

	int start = -1;         //To store the starting index of the substring
    int ans = INT_MAX;      //To store the length of the shortest substring
    pair<int,int> p;        //To store the starting and ending index of the substring

	for(int i=0;i<A.size();i++){    
        //Insert each element of A into Amap with its frequency
        Amap[A[i]]++;

        bool flag = true;   //Assume frequency of current A element is more in Amap than Bmap
        for(auto it=Bmap.begin();it!=Bmap.end();it++){
            //Check the assumption for each char in Bmap
            if(it->second > Amap[it->first]){
                //Assumption proven wrong , do nothing and iterate for next element till it becomes true
                flag = false;
                break;
            }
        }
        if(flag){
            //If assumption remains true i.e. freq of every element in Bmap is less than its freq in Amap
            //Check for the substring
            while(Amap[A[start+1]] > Bmap[A[start+1]]){
                //Decrease the freq of char at (start+1) index to remove the redundant characters from the substring 
                //and minimise the length of the substring
                Amap[A[start+1]]--;
                start++;    //Increment start pointer after removing the redundant characters
            }
            if(ans > i-start){
                //Choose the minimum length substring and store the length in ans variable
                //Store the starting and ending indices of the substring in the pair
                ans = min(ans,i-start);
                p = make_pair(start+1,i);
            }
        }
	}
    if(ans == INT_MAX){
        cout<<"No String";
    }
    else {
        for(int i=p.first;i<=p.second;i++){
            cout<<A[i];
        }
    }
	return 0;
	
}
