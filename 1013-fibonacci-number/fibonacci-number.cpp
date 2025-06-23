#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int>dp;
    int func(int n){
        
        if(n<=1) return n;
        if(dp[n]!= -1) return dp[n];

        else {
            dp[n] = func(n-1)+func(n-2);
            return dp[n];
        }
    }
    int fib(int n) {
        dp.resize(n+1,-1);
        return func(n);
    }
};