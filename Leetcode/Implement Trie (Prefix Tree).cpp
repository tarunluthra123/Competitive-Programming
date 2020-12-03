class Trie {
private:
    struct node {
        char c;
        unordered_map<char, node*> m;
        bool end;
        node(char ch, bool terminal = false) {
            c = ch;
            end = terminal;
        }
    };
    node *trie;
public:
    /** Initialize your data structure here. */
    Trie() {
        trie = new node('.');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node *curr = trie;
        for (int i = 0; i < word.size(); i++) {
            if (curr->m.count(word[i]) == 0)
                curr->m[word[i]] = new node(word[i]);
            curr = curr->m[word[i]];
        }
        curr->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *curr = trie;
        for (int i = 0; i < word.size(); i++) {
            if (curr->m.count(word[i]) == 0)return false;
            curr = curr->m[word[i]];
        }
        return curr->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        node *curr = trie;
        for (int i = 0; i < word.size(); i++) {
            if (curr->m.count(word[i]) == 0)return false;
            curr = curr->m[word[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
