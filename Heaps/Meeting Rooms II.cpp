// https://www.interviewbit.com/problems/meeting-rooms/
int Solution::solve(vector<vector<int> > &A) {
    if (A.size() == 0) return 0;
    sort(A.begin(), A.end(), [](vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    });
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(A[0][1]);
    for (int cur = 1; cur < A.size(); cur++) {
        int cur_start = A[cur][0], early_end = pq.top();
        pq.pop();
        if (cur_start >= early_end) {
            // no overlap hence cur meeting can be accomodated in the same room with the earliest end time
            early_end = A[cur][1];
        }
        else {
            // overlap so we need to find a new meething room for this
            pq.push(A[cur][1]);
        }
        pq.push(early_end);
    }
    return pq.size();
}
