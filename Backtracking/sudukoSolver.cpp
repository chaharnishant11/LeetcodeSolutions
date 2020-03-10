/* Method1 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]={0}; 
        int cols[9][9]={0}; 
        int blocks[3][3][9]={0};
        for(int r=0;r<9;r++)    
            for(int c=0;c<9;c++)
                if(board[r][c]!='.'){   
                    int number=board[r][c]-'1'; 
                    if(rows[r][number]++) return false; 
                    if(cols[c][number]++) return false;
                    if(blocks[r/3][c/3][number]++) return false;
                }
        return true;
    }
};

/* Method2*/

class Solution {
public:
    bool issafe(vector<vector<char>> board,int x,int y,int num){
        for(int i=0;i<9;i++){
            if(board[x][i]!='.' && i!=y){
                if(board[x][i]-'0'==num){
                    return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][y]!='.' && i!=x){
                if(board[i][y]-'0'==num){
                    return false;
                }
            }
        }
        int l=(x/3)*3;
        int m=(y/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[l+i][m+j]!='.' && l+i!=x && m+j!=y){
                    if(board[l+i][m+j]-'0'==num){
                        return false;
                    }
                }
                
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!issafe(board,i,j,board[i][j]-'0')) return false;
                }
            }
        }
        return true;
    }
};