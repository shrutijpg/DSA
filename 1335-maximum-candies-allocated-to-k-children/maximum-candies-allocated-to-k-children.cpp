class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, long long x) {
        if (x == 0) return true; // always possible to give 0 candies per child
        long long count = 0;
        for (int c : candies) {
            count += c / x; // how many children can be served from this pile
            if (count >= k) return true; // early stop
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 0; // min candies per child
        long long high = accumulate(candies.begin(), candies.end(), 0LL) / k; 
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canDistribute(candies, k, mid)) {
                ans = mid;
                low = mid + 1; // try to maximize
            } else {
                high = mid - 1; // need to reduce x
            }
        }
        return (int)ans;
    }
};
