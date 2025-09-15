// O(n) time on average, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;
        for (int x : s) {                // iterate over unique elements
            if (s.find(x - 1) == s.end()) { // x is sequence start
                int curr = x;
                int len = 1;
                while (s.find(curr + 1) != s.end()) {
                    curr += 1;
                    ++len;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};

// Example usage:
// int main() {
//     Solution sol;
//     vector<int> nums = {100, 4, 200, 1, 3, 2};
//     cout << sol.longestConsecutive(nums) << "\n"; // prints 4 (1,2,3,4)
// }
