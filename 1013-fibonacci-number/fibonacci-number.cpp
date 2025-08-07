#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // Optimizing vector<int>dp;
    int func(int i,vector<int>&dp){
        if(i<=1){
            return i;
        }
        if (dp[i] != -1) return dp[i];
        return dp[i]=func(i-1,dp)+func(i-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return func(n,dp);
    }
};