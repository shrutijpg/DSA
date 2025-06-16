class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack < int > st;
        int maxA = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
          while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int ht = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
              width = i;
            else
              width = i - st.top() - 1;
            maxA = max(maxA, width * ht);
          }
          st.push(i);
        }
        return maxA;
    }
};