#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // Optimizing vector<int>dp;
    int func(int n){
        int prev2 =0;
        int prev=1;
        if(n==0) return 0;

        for(int i=2;i<=n;i++){
            int curi = prev+prev2;
            prev2=prev;
            prev=curi;

        }
        return prev;
    }
    int fib(int n) {
        return func(n);
    }
};