// Understand Time complexity for recursive method - https://leetcode.com/problems/word-break/discuss/169383/solved-The-Time-Complexity-of-The-Brute-Force-Method-Should-Be-O(2n)-and-Prove-It-Below
// Recursion - O(2^(n-1))
class Solution {
public:
    bool word_break(int idx, string cur, string &s, unordered_set<string> &words) {
        for (int i = idx; i < s.size(); i++) {
            cur += s[i];
            if (words.count(cur) == true) {
                if (i == s.size()-1) return true;
                if (word_break(i + 1, "", s, words) == true) return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string word: wordDict) {
            words.insert(word);
        }
        string cur = "";
        return word_break(0, cur, s, words);
    }
};


// DP - O(N^2), Also solution for count the total number of sentences possibe
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string word: wordDict) {
            dict.insert(word);
        }
        int n = s.size();
        // count_sentences[i] => store the total number of different sentences can be formed by using the words in the dictionary till the ith char in th i/p string
        // just to handle the current ques I am making it a bool vector as counting the number of sentencing is going out of bounds in same test cases
        vector<bool> count_sentences(n, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                // Now for each pottential cur_word, we'll try to see if we can find a suffix that is actually a valid word and if we find a valid suffix then we'll confirm if the prefix for that suffix is also  a valid word and if it is, that means we can generate a valid sentence by dividing the cur_word from that index
                string suffix = s.substr(j, i - j + 1); 
                if (dict.count(suffix) == true) {
                    // if suffix is valid, we confirm that the corresponding prefix is also valid
                    if (j > 0) {
                        // so for the current valid suffix word from s[j..i], we get the number of sentences possible from s[0...j-1] from count_sentence[j-1], if this is > 0 then that means we can generate same number of valid sentences bby uncluding the current suffix into the sentence till j-1 also
                        count_sentences[i] = count_sentences[i] or count_sentences[j-1]; 
                    }
                    else {
                        // i.e. when j == 0, so  it means we are considering the entire cur_word (s[0...i]) as the suffix and as the cur_word is a valid word, so we can say that we can form 1 valid sentence till the ith char in s 
                        count_sentences[i] = true;
                    }
                }
            }
        }
        // Now after the 2 nested for loops are done, count_sentences[n-1] will contain the number of valid sentences could be genrated by breaking down s string acc. to the dict words, so if count_sentences[n-1] > 0, that means atleast 1 valid sentence exists using the dict words
        return count_sentences[n-1];
    }
};
