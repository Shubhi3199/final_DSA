// Time - O(3N) & Space - O(2N)
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int size = arr.size();
        vector<int> prefix_increasing(size, 1); // prefix_increasing[i] => The number consecutive elements to the left of i (including the current ele) which are strictly increasing
        vector<int> suffix_increasing(size, 1); // same as above but to the right of i (including the current ele)
        for (int idx = 1; idx < size; idx++) {
            if (arr[idx-1] < arr[idx]) prefix_increasing[idx] = prefix_increasing[idx-1] + 1;
        }
        for (int idx = size-2; idx >= 0; idx--) {
            if (arr[idx] > arr[idx + 1]) suffix_increasing[idx] = suffix_increasing[idx+1] + 1;
        }
        int max_len = 0;
        for (int idx = 1; idx < size-1; idx++) {
            if (arr[idx-1] < arr[idx] and arr[idx] > arr[idx+1]) {
                max_len = max(max_len, prefix_increasing[idx-1] + suffix_increasing[idx+1] + 1);
            }
        }
        return max_len;
    }
};

// Time - O(1N) & Space - O(1)
class Solution {
public:
    int longestMountain(vector<int> A) {
        int res = 0, up = 0, down = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (down && A[i - 1] < A[i] || A[i - 1] == A[i]) up = down = 0;
            up += A[i - 1] < A[i];
            down += A[i - 1] > A[i];
            if (up && down) res = max(res, up + down + 1);
        }
        return res;
    }
};
