class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_occur(26);
        for (int idx = 0; idx < s.size(); idx++) {
            last_occur[s[idx] - 'a'] = idx;
        }
        vector<int> partitions;
        
        for (int idx = 0; idx < s.size();) {
            int end = max(last_occur[s[idx] - 'a'], end);
            int start = idx;
            while (start <= end) {
                end = max(last_occur[s[start] - 'a'], end);
                start++;
            }
            partitions.push_back(start - idx);
            idx = start;
        }
        return partitions;
    }
};
