class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();

        int summax =0;
        

        for(int i =0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum = sum+accounts[i][j];
            }
            
            summax= max(summax,sum);

        }
        return summax;
    }
};