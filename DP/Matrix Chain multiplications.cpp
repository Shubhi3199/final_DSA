class Solution{
public:
    int minMultipications(int arr[], int n){
        // min_multiply[i][j] => stores the min multiplication in multiplying matrices from i to j
        vector<vector<int>> min_multiply(n-1, vector<int> (n-1, 0)); // we take the size of dp array as n-1 as the arr has 1 extra dimension to accomodate matrix dimension
        int size = min_multiply.size();
        for (int gap = 0; gap < size; gap++) {
            for (int start = 0; start + gap < size; gap++) {
                int end = start + gap;
                if (gap == 0) {
                    min_multiply[start][end] = 0; // as we are only dealing with a single matrix which has 0 cost of multiplication
                }
                else if (gap == 1) {
                    // cost of multiplying two adjacent matrices, as the first matrix has a dimensions of (arr[start] * arr[end])
                    // and the second matrix has dimensions of arr[end] * arr[end + 1]
                    min_multiply[start][end] = arr[start] * arr[end] * arr[end + 1]; 
                }
                else {
                    int min_cost = INT_MAX;
                    // when we are multiplying more than 3 matricies, so now we'll have to brek down the product into smaller halfs
                    // for ex. if we wan the product of (A.B.C.D) matrices, it can be dived as - 
                    // (A)(BCD) Vs (AB)(CD) Vs (ABC)(D), for that we need a divider, as we have divided the entire product into left aand right half
                    for (int divider = start; divider < end; divider++) {
                        int left_cost = min_multiply[start][divider];
                        int right_cost = min_multiply[divider+1][end];
                        int multiplier_cost = arr[start] * arr[divider+1] * arr[end+1];
                        min_cost = min(min_cost, left_cost + right_cost + multiplier_cost);
                    }
                    min_multiply[start][end] = min_cost;
                }
            }
        }
        return min_multiply[0][size-1];
    }
};
