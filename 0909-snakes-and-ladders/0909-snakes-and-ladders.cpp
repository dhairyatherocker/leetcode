// class Solution {
// public:
//     int snakesAndLadders(vector<vector<int>>& board) {
//     int n=board.size();
//     int dest_cell=n*n;    
//     vector<int>vis(dest_cell+1,INT_MAX);
//     queue<pair<int,int>>q;
//     vis[1]=0;
//     q.push({1,0});
//     int max_dis=INT_MAX;
//     while(!q.empty()){
//     auto [curr_cell,chance]=q.front();
//     q.pop();
//     int start=curr_cell+1;
//     int end=min(dest_cell,curr_cell+6);
//     if(curr_cell==dest_cell){
//     return chance;    
//     }
//     for(int i=start;i<=end;i++){
//     if(vis[i]>chance+1){
//     vis[i]=chance+1;
//     // int row=n-(i/n);
//     // if(i%n!=0) row--;
//     int row = n - 1 - (i - 1)/n;
//     int col;
//     // if(row%2==0) col=n-(i%n);
//     // else col=(i%n)-1;
//     int position = (i-1)%n;
//     if ((n-1-row)%2 == 0)
//     col = position;
//     else
//     col = n-1-position;
//     if(board[row][col]!=-1 && vis[board[row][col]]>chance+1){
//     vis[board[row][col]]=chance+1;
//     q.push({board[row][col],chance+1});    
//     }
//     else if(board[row][col]==-1) q.push({i,chance+1});     
//     }

//     }
//     }
//    return max_dis==INT_MAX?-1:max_dis;
//     }
// };

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int dest_cell = n*n;

        vector<int> vis(dest_cell+1, INT_MAX);
        queue<pair<int,int>> q;

        vis[1] = 0;
        q.push({1,0});

        while(!q.empty()) {
            auto [curr_cell,chance] = q.front();
            q.pop();

            if(curr_cell == dest_cell)
                return chance;

            int start = curr_cell+1;
            int end = min(dest_cell,curr_cell+6);

            for(int i=start; i<=end; i++) {
                 int row = n - 1 - (i - 1)/n;
    int position = (i-1)%n;

    int col;
    if((n-1-row)%2 == 0)
        col = position;
    else
        col = n-1-position;

    int next = i;

    if(board[row][col] != -1)
        next = board[row][col];

    if(vis[next] > chance+1) {
        vis[next] = chance+1;
        q.push({next, chance+1});
    }
            }
        }

        return -1;
    }
};
