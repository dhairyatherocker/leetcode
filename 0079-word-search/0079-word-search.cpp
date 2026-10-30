class Solution {
public:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    bool dfs(int row,int col,int pointer,vector<vector<bool>>&vis,string &word,vector<vector<char>>&board){
    vis[row][col]=true;
    if(pointer==word.size()-1) return true;
    for(int i=0;i<4;i++){
    int new_row=row+drow[i];
    int new_col=col+dcol[i];
    if(new_row>=0 && new_row<board.size() && new_col>=0 && new_col<board[0].size() && !vis[new_row][new_col] && word[pointer+1]==board[new_row][new_col] && dfs(new_row,new_col,pointer+1,vis,word,board)) return true;    
    }
     vis[row][col] = false; 
    return false;    
    }
    bool exist(vector<vector<char>>& board, string word) {
    int n=word.size();
    for(int i=0;i<board.size();i++){
    for(int j=0;j<board[0].size();j++){
    if(board[i][j]==word[0]){
    vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
    if(dfs(i,j,0,vis,word,board)) return true;     
    }    
    }}
    return false; 
    }
};