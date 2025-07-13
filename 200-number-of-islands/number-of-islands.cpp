class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m  = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traversing in the neighbours and mark 
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};