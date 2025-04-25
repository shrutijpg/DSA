class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start;
        for (auto& row : board)
            for (int num : row)
                start += (num + '0');

        // Neighbors of each index (based on 2x3 board layout)
        vector<vector<int>> neighbors = {
            {1, 3},        // index 0
            {0, 2, 4},     // index 1
            {1, 5},        // index 2
            {0, 4},        // index 3
            {1, 3, 5},     // index 4
            {2, 4}         // index 5
        };

        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);

        int steps = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front(); q.pop();
                if (curr == target)
                    return steps;

                int zero_pos = curr.find('0');
                for (int neighbor : neighbors[zero_pos]) {
                    string next = curr;
                    swap(next[zero_pos], next[neighbor]);
                    if (visited.count(next) == 0) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            steps++;
        }

        return -1; // not solvable
    }
};