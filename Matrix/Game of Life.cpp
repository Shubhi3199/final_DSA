class Solution {
public:
    bool is_cell_valid(int row, int col, vector<vector<int>> &board) {
        return row >= 0 and row < board.size() and col >= 0 and col < board[0].size() and (board[row][col] == 3 or board[row][col] == 1);
    }
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    int cnt_live_nbrs(int row, int col, vector<vector<int>> &board) {
        int live_nbrs = 0;
        for (vector<int> dir: directions) {
            int new_r = row + dir[0], new_c = col + dir[1];
            if (is_cell_valid(new_r, new_c, board)) {
                live_nbrs++;
            }
        }
        return live_nbrs;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        // old state   new state  key
        //    0            0       0
        //    0            1       2
        //    1            0       1
        //    1            1       3
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int live_nbrs = cnt_live_nbrs(row, col, board);
                if (board[row][col] == 0) {
                    if (live_nbrs == 3) {
                        // 0 -> 1 (convert)
                        board[row][col] = 2;
                    }
                    else board[row][col] = 0;
                }
                else {
                    if (live_nbrs < 2 or live_nbrs > 3) {
                        // 1 -> 0 (convert)
                        board[row][col] = 1;
                    } 
                    else board[row][col] = 3;
                }
            }
        }
        // key to new_state coversion
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (board[row][col] == 1) board[row][col] = 0;
                else if (board[row][col] == 2) board[row][col] = 1;
                else if (board[row][col] == 3) board[row][col] = 1;
            }
        }
    }
};
