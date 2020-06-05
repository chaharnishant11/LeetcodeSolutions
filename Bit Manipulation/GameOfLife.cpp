class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int d[][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int live = 0;
                for(int k = 0; k < 8; k++){
                    int x = d[k][0] + i;
                    int y = d[k][1] + j;
                    if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                        continue;
                    }
                    if(board[x][y] & 1) {
                        live++;
                    }
                }
                if(board[i][j] == 0) {
                    if(live == 3){
                        board[i][j] = 2; // 2 : (10)
                    }
                }
                else {
                    if(live < 2 || live > 3){
                        board[i][j] = 1; // 1 : (01)
                    }else{
                        board[i][j] = 3; // 3 : (11)   
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                board[i][j] >>=1;
            }
        }    
    }
};