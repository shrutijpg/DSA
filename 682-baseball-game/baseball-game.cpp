#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (string& op : ops) {
            if (op == "C") {
                st.pop();  // Remove last valid score
            } else if (op == "D") {
                st.push(2 * st.top());  // Double last score
            } else if (op == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);          // restore top1
                st.push(top1 + top2);   // push their sum
            } else {
                st.push(stoi(op));  // Convert string to int and push
            }
        }

        int total = 0;
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};
