#include <vector>
#include <algorithm>

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+1,0),cur(n+1,0);
        for(int ind =n-1;ind>=0;ind--){
            for(int prevInd=ind-1;prevInd>=-1;prevInd--){
                int len = next[prevInd+1];
                if(prevInd==-1 || nums[ind]>nums[prevInd]){
                    len = max(len,(1+ next[ind+1]));
                }
                cur[prevInd+1] = len;
            }
            next = cur;
        }
        return cur[-1+1];
    }
};