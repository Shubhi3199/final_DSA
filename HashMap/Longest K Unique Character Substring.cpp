// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int start = 0, end = 0;
        unordered_map<char, int> freq_map;
        int max_size = -1;
        while (end < s.size()) {
            freq_map[s[end]]++;
            if (freq_map.size() == k) max_size = max(max_size, end - start  + 1);
            while (freq_map.size() > k) {
                freq_map[s[start]]--;
                if (freq_map[s[start]] == 0) freq_map.erase(s[start]);
                start++;
            }
            end++;
        }
        if (max_size != -1) max_size = max(max_size, end - start);
        return max_size;
    }
};
