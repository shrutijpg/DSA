class Solution {
private:
    void bfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int color,int iniColor,int n,int m){
        ans[row][col] = color; //newcolor

        queue<pair<int,int>>q;
        q.push({row,col});


        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};


        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i =0;i<4;i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];


                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==iniColor && ans[nr][nc] != color ){
                    ans[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
        
       bfs(sr,sc,ans,image,color,iniColor,n,m);
        return ans;
    }
};