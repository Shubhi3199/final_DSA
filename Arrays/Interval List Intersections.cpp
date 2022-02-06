class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int start1 = 0, start2 = 0;
        vector<vector<int>> intersection;
        while (start1 < first.size() and start2 < second.size()) {
            int head = max(first[start1][0], second[start2][0]);
            int tail = min(first[start1][1], second[start2][1]);
            if (tail >= head) intersection.push_back({head, tail});
            
            if (first[start1][1] < second[start2][1]) {
                start1++; // as this is the smaller out of the 2
            }
            else if (second[start2][1] < first[start1][1]) {
                start2++; // as this is the smaller out of the 2
            }
            else {
                start1++; start2++;// as both are equal, so we have exhausted both
            }
        }
        return intersection;
    }
};
