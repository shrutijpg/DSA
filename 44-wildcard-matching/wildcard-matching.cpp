class Solution {
public:
    int func(int i, int j,string &s, string &p,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0) {
            for(int k=0;k<=i;k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(p[i] == s[j] || p[i]=='?'){
            return dp[i][j]= func(i-1,j-1,s,p,dp);
        }
        if(p[i]=='*'){
            return dp[i][j]= func(i-1,j,s,p,dp)||func(i,j-1,s,p,dp);
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return func(n-1,m-1,s,p,dp);
    }
};