#include <vector>
#include <stack>
#include <unordered_map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;
        stack<int> st;

        for(int i=nums2.size()-1; i>=0 ;--i){
            int cur = nums2[i];
            while(!st.empty() && st.top()<= cur ){
                st.pop();
            }
            if(st.empty()) ngeMap[cur] = -1;
            else ngeMap[cur] = st.top();


            st.push(cur);
        }
        vector<int> result;
        for (int num : nums1) {
            result.push_back(ngeMap[num]);
        }

        return result;

    }
};