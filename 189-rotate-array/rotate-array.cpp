class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // handle if k > n

        // store last k elements in temp
        vector<int> temp(k);
        for(int i=0; i<k; i++) {
            temp[i] = nums[n-k+i];
        }

        // shift the remaining n-k elements to the right
        for(int i=n-1; i>=k; i--) {
            nums[i] = nums[i-k];
        }

        // copy temp back to the beginning
        for(int i=0; i<k; i++) {
            nums[i] = temp[i];
        }
    }
};
