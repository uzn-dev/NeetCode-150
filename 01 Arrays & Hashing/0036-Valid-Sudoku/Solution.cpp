class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0}; //[位置][數字]:出現過1，沒出現過0
        int col[9][10] = {0};
        int box[9][10] = {0};
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0'; //利用 ASCII 相減
                int box_idx = (i/3) * 3 + (j/3); //重新編號九宮格轉一維索引

                //檢查是否在任一種有重複
                if(row[i][num] || col[j][num] || box[box_idx][num]){
                    return false;
                }
                row[i][num] = col[j][num] = box[box_idx][num] = 1;
            }
        }
        return true;
    }
};