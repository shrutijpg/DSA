class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int color,int iniColor,int delRow[],int delCol[]){
        ans[row][col] = color;  // new color
        int n = image.size();
        int m = image[0].size();

        for(int i=0;i<4;i++){
            int nr = row+delRow[i];
            int nc = col + delCol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] ==iniColor && ans[nr][nc] != color){
                dfs(nr,nc,ans,image,color,iniColor,delRow,delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        dfs(sr,sc,ans,image,color,iniColor,delRow,delCol);
        return ans;
    }
};