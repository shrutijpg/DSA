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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> psum(m,0);
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    psum[j] += 1;
                }
                else{
                    psum[j]=0;

                }
            }
            maxArea = max(maxArea,largestRectangleArea(psum));
        }
        return maxArea;
    }
};