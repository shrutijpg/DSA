#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // Optimizing vector<int>dp;

    int fib(int n) {
        if(n<=1) return n;
        return fib(n-1)+fib(n-2);
    }
};