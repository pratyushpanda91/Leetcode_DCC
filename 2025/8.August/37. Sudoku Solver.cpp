#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool find_empty(vector<vector<char>>& board,int &row,int &col){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row=i,col=j;
                    return true;
                }
            }
        }
        return false;
    }
    void set_char(vector<vector<char>>& board,int row,int col,char c){
        board[row][col]=c;
    }
    void reset_char(vector<vector<char>>& board,int row,int col){
        board[row][col]='.';
    }
    bool valid_h(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c){
                return false;
            }
        }
        return true;
    }
    bool valid_v(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c){
                return false;
            }
        }
        return true;
    }
    bool valid_b(vector<vector<char>>& board,int row,int col,char c){
        int startr=(row/3)*3;
        int startc=(col/3)*3;
        for(int i=startr;i<startr+3;i++){
            for(int j=startc;j<startc+3;j++){
                if(board[i][j]==c){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
            int row,col;
            // find empty posn
            if(find_empty(board,row,col)){
                int flag=0;
                for(int i=1;i<10;i++){
                    char c='0'+i;
                    // check valid horizontal
                    bool h=valid_h(board,row,col,c);
                    // check valid vertical
                    bool v=valid_v(board,row,col,c);
                    // check valid in box
                    bool b=valid_b(board,row,col,c);
                    // if all valid => set and call solve again
                    if(h&&v&&b){
                        flag=1;
                        // set char
                        set_char(board,row,col,c);
                        if(solve(board)){
                            return true;
                        }
                        // reset in backtracking
                        reset_char(board,row,col);
                    }
                }
                if(flag==0){
                    return false;
                }
            }else{
                return true;
            }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
