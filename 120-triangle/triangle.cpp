class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(triangle[n-1]);

        for(int j =0;j<n;j++){
            front[j] = triangle[n-1][j];

        }
        for(int i=n-2;i>=0;i--){
            vector<int>cur(i+1);
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + front[j];
                int dia = triangle[i][j] +front[j+1];
                //int diaL = minimumTotal(triangle)+front[j-1];


                cur[j] = min(down,dia);

            }
            front = cur;
        }
        return front[0];

    }
};