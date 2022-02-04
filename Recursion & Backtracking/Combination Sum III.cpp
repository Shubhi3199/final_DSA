class Solution {
public:
    void get_all_combinations(int cur_num, int target, int k, vector<int> &cur_combi, vector<vector<int>> &res) {
        if (k == 0) {
            if (target == 0) {
                res.push_back(cur_combi);
            }
            return;
        }
        if (target == 0 and k != 0) return; 
        for (int i = cur_num; i <= 9 and target >= i; i++) {
            cur_combi.push_back(i);
            get_all_combinations(i + 1, target - i, k-1, cur_combi, res);
            cur_combi.pop_back();
        }  
    }
        
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur_combi;
        vector<vector<int>> res;
        get_all_combinations(1, n, k, cur_combi, res);
        return res;
    }
};
