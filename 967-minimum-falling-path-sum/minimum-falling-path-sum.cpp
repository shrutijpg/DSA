class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0);
        vector<int> cur(m);

        
        if(n==1 && m==1) return matrix[0][0];
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j =0;j<m;j++){

                
                int up = matrix[i][j] + prev[j];
                int leftDiagonal = (j > 0) ? matrix[i][j] + prev[j - 1] : INT_MAX;
                int rightDiagonal = (j < m - 1) ? matrix[i][j] + prev[j + 1] : INT_MAX;

                cur[j] = min({up, leftDiagonal, rightDiagonal});
            }
            prev = cur;
        }
        return *min_element(prev.begin(), prev.end());
    }
};