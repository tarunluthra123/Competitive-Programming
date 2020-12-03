class WordDictionary {
    struct node {
        char c;
        unordered_map<char,node*> m;
        bool end;
        node(char ch,bool e=false){
            c = ch;
            end = e;
        }
    };
    node *head;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new node(';');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        node *curr = head;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(curr->m.count(c) == 0){
                curr->m[c] = new node(c);
            }
            curr = curr->m[c];
        }
        curr->end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word,node *h = NULL) {
        if(!h)h = head;
        node *curr = h;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                string ros = word.substr(i+1);
                bool ans = 0;
                for(pair<char,node*> p : curr->m){
                    ans = ans || search(ros,p.second);
                }
                return ans;
            }
            if(curr->m.count(word[i]) == 0)
                return false;
            curr = curr->m[word[i]];
        }

        return curr->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
