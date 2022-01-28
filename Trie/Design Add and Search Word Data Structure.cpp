class TrieNode {
public:
    TrieNode* nbrs[26];
    bool is_end;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            nbrs[i] = NULL;
        }
        is_end = false;
    }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char ch: word) {
            int idx = ch - 'a';
            if (cur -> nbrs[idx] == NULL) cur -> nbrs[idx] = new TrieNode();
            cur = cur -> nbrs[idx];
        }
        cur -> is_end = true;
    }
    
    bool _search(string word,TrieNode* cur_node) {
        for (int idx = 0; idx < word.size(); idx++) {
            char ch = word[idx];
            int num = ch - 'a';
            if (ch != '.') {
                if (cur_node -> nbrs[num] == NULL) return false;
                else cur_node = cur_node -> nbrs[num];
            }
            else {
                for (int i = 0; i < 26; i++) {
                    if (cur_node -> nbrs[i] != NULL) {
                        string sub = word.substr(idx+1, word.size()-idx-1);
                        if (_search(sub, cur_node -> nbrs[i])) return true;
                    }
                }
                return false;
            }
        }
        return cur_node -> is_end;
    }
    
    bool search(string word) {
        return _search(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
