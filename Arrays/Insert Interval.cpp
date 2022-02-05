class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_intv) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int idx = 0; idx < intervals.size(); idx++) {
            vector<int> cur_intv = intervals[idx];
            if (new_intv[0] <= cur_intv[0]) {
                // this is the correct position for insertion of this new interval, but there can be 3 ways of overlap, 1. From left, 2. From right and 3. From both sides
                int start = new_intv[0], end = new_intv[1];
                if (merged.empty() == false and merged.back()[1] >= start) {
                    // overlap exists in the left
                    start = min(start, merged.back()[0]);
                    end = max(end, merged.back()[1]);
                    merged.pop_back();
                }
                int i = idx;
                while (i < intervals.size() and end >= intervals[i][0]) {
                    // overlap exists on the right 
                    end = max(end, intervals[i][1]);
                    i++;
                }
                merged.push_back({start, end});
                while (i < intervals.size()) {
                    merged.push_back(intervals[i]);
                    i++;
                }
                return merged;
            }
            else {
                merged.push_back(cur_intv);
            }
        }
        if (intervals.size() == 0) merged.push_back(new_intv);
        else if (new_intv[0] >= intervals[intervals.size()-1][0]) {
            if (merged.empty() == false and merged[merged.size()-1][1] >= new_intv[0]) {
                new_intv[0] = min(new_intv[0], merged[merged.size()-1][0]);
                new_intv[1] = max(new_intv[1], merged[merged.size()-1][1]);
                merged.pop_back();
            }
            merged.push_back(new_intv);
        }
        return merged;
    }
};
