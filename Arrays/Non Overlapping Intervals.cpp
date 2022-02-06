class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        vector<int> prev_intv = intervals[0];
        for (int idx = 1; idx < intervals.size(); idx++) {
            vector<int> cur_intv = intervals[idx];
            if (cur_intv[0] < prev_intv[1]) {
                // overlap condition, so we'll delete the one with larger end as it might intersect with the incoming intervals
                cnt++;
                if (cur_intv[1] < prev_intv[1]) {
                    prev_intv = cur_intv; // and get rid of prev intv as it has a greated end, otherwise prev remains same as cur_intv will be deleted
                }
            }
            else prev_intv = cur_intv;
        }
        return cnt;
    }
};
