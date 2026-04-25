class Solution {
private:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;


        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};


        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Exploring neighbours
            for(int i=0;i<4;i++){
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];

                if(nrow>=0 && nrow<n &&
                   ncol>=0 && ncol<m &&
                   grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                }
        }


        }

        

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count =0;

        //traversing the grid
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};