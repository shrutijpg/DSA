#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        // Min-heap: (distance, row, col)
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        pq.push({1, 0, 0});

        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) return d;

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        pq.push({dist[nr][nc], nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};
