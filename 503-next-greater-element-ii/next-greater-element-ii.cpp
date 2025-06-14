#include <vector>
#include <stack>
#include <unordered_map>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> st;
        int n = nums.size();
        vector<int> ngeMap(n);
        for(int i=2*n-1; i>=0 ;--i){
            while(!st.empty() && st.top()<= nums[i%n]){
                st.pop();
            }
            if(i<n){
                ngeMap[i] = st.empty()? -1:st.top();
            }
            st.push(nums[i%n]);

        }
        

        return ngeMap;
    }
};