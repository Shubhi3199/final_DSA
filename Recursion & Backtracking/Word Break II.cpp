class Solution {
public:
    bool word_break(int idx, string cur_word, string &cur_sentence, vector<string> &res, string &s, unordered_set<string> &words) {
        for (int i = idx; i < s.size(); i++) {
            cur_word += s[i];
            if (words.count(cur_word) == true) {
                string prev_state = cur_sentence;
                cur_sentence += (cur_word + " ");
                if (i == s.size()-1) {
                    cur_sentence.pop_back(); // remove one extra space at the end
                    res.push_back(cur_sentence);
                    return true;
                }
                word_break(i + 1, "", cur_sentence, res, s, words);
                // backtracking stage, where we'll remove the last added word in the cur_sentence so that we can create annother sentence
                cur_sentence = prev_state; // prev_state of the sentence before adding the cur word
            }
        }
        return false;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string word: wordDict) {
            words.insert(word);
        }
        vector<string> res;
        string cur_sentence = "";
        word_break(0, "", cur_sentence, res, s, words);
        return res;
    }
};
