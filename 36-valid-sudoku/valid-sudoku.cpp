class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int>mp;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++) {
                if(mp[board[i][j]]){
                    return false;
                }
                if(board[i][j] != '.') mp[board[i][j]]++;
            }
            mp.clear();
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++) {
                if(mp[board[j][i]]){
                    return false;
                }
                if(board[j][i] != '.') mp[board[j][i]]++;
            }
            mp.clear();
        }
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                mp.clear();
                for(int r = i; r < i+3; r++) {
                    for(int c = j; c < j+3; c++) {
                        if(board[r][c] != '.') {
                            if(mp[board[r][c]] > 0)
                                return false;
                            mp[board[r][c]]++;
                        }
                    }
                }
            }
        }

        return true;
    }
};