/*
Digital Dictionary


Peter found a digital dictionary which is far better than normal dictionaries. The digital dictionary has an input field in which one can search any string and the dictionary displays all the words whose prefix is that input string. Now you are given a task to make your own digital dictionary. You will be given words that you can store in your database and then you need to design the search functionality. And if no such words are available, add this word to your dictionary.

Input Format
Single integer N which denotes the number of words which are to be stored in the database of the dictionary. N lines of input, where in each line there is a string made up of lowercase/uppercase letter Single integer Q which denotes the number of queries. Q number of lines describing the query string on each line given by user.

Constraints
1=N=30000 sum(len(stringi))=2*10^5 1=Q=10^3

Output Format
If word with prefix exists in the database, then you need to print all the words with the given prefix in lexicographical order in separate lines else you need to print No suggestions

Sample Input
4
pet
peter
rat
rack
5
pe
pet
r
rac
rat
Sample Output
pet
peter
pet
peter
rack
rat
rack
rat
*/
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    char ch;
    bool isLast;
    unordered_map<char,node*> m;
    node(char c) {
        ch = c;
        isLast = false;
    }    
};

class Trie {
private :
    node * head;
public :
    Trie() {
        head = new node('.');
    }

    void addWord(string s) {
        node * current = head;
        for (int i = 0; i < s.size(); ++i) {
            char temp = s[i];
            if(current->m.find(temp) == current->m.end()) {
                current->m[temp] = new node(temp);
            }
            current = current->m[temp];
        }
        current->isLast = true;
    }


    bool search(string s) {
        node * current = head ; 
        for (int i = 0; i < s.size(); ++i) {
            char temp = s[i];
            if(current->m.find(temp) == current->m.end()) {
                return false;
            }
            current = current->m[temp];
        }
        return current->isLast ;
    }

    bool searchKey(string s) {
        node * current = head ; 
        for (int i = 0; i < s.size(); ++i) {
            char temp = s[i];
            if(current->m.find(temp) == current->m.end()) {
                return false;
            }
            current = current->m[temp];
        }
        return true;
    }


    void printAll(node *current, string prevString) {
        if(current->isLast) {
            cout << prevString << endl;
        }

        for (char x = 'a'; x <= 'z'; ++x) {
            if(current->m.find(x) != current->m.end()) {
                printAll(current->m[x], prevString+x);
            }
        }
    }


    void printWordsFromKey(string s) {
        if(!searchKey(s)) {
            addWord(s);
            cout << "No suggestions\n";
            return ;
        }

        node * current = head;
        for (int i = 0; i < s.size(); ++i) {
            char temp = s[i];
            current = current->m[temp];
        }

        printAll(current, s);
    }
};

int main() {
    Trie t;

    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        t.addWord(s);
    }

    int query;
    cin >> query;
    while(query--) {
        string s;
        cin >> s;
        t.printWordsFromKey(s);
    }

    return 0;
}
