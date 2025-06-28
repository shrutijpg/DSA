class Solution {
public:
    int func(int i , int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 && j== 0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp [i][j];
        int up = grid[i][j] + func(i-1,j,grid,dp);
        int left = grid[i][j] + func(i,j-1,grid,dp);

        return dp[i][j] = min(up,left);


    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>prev(m,0);
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            vector<int> cur(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j== 0) cur[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0) up += prev[j];
                    else up +=  1e9;

                    int left = grid[i][j];
                    if(j>0) left += cur[j-1];
                    else left+= 1e9;

                    cur[j] = min(up,left);

                }
            }
            prev = cur;
        }


        return prev[m-1];
    }
};