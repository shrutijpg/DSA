class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long curTime = 0;
        long long wtTime = 0;
        int n = customers.size();

        for (int i = 0; i < n; i++) {
            int arrT = customers[i][0];
            int prep = customers[i][1];

            curTime = max(curTime, (long long)arrT);
            curTime += prep;
            wtTime += curTime - arrT;
        }

        return (double)wtTime / n;
    }
};
