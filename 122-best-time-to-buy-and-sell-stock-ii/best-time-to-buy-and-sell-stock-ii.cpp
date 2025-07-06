class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        long profit;
        vector<long> ahead(2,0),cur(2,0);
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        ahead[0] = ahead[1] =0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++ ){
                if(buy){
                    profit = max((-prices[ind]+ ahead[0]),ahead[1]);
                }
                else{
                    profit = max((prices[ind]+ ahead[1]),ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead = cur;
        }
        
        return ahead[1];
    }
};