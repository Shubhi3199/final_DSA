class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // sorting intervals by thier starting time so that all the intervals which might overlap are palced next to each other
        vector<vector<int>> merged;
        for (vector<int> cur_intv: intervals) {
            if (merged.empty() == true or cur_intv[0] > merged.back()[1]) {
                // either no intvl added in the ans yet or overlap does not exists
                merged.push_back(cur_intv); // so we just push the new interval as there is no ovrlap
            }
            else {
                // overlap exists and the cur_intv shuold be merged with the last non-overlapping interval
                merged.back()[1] = max(merged.back()[1], cur_intv[1]);
            }
        }
        return merged;
    }
};
