class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int total_sum = 0, single_digit_sum = 0, double_digit_sum = 0;

        for (int num : nums) {
            total_sum += num;
            if (num < 10)
                single_digit_sum += num;
            else
                double_digit_sum += num;
        }

        // Case 1: Alice chooses all single-digit numbers
        if (single_digit_sum > total_sum - single_digit_sum)
            return true;

        // Case 2: Alice chooses all double-digit numbers
        if (double_digit_sum > total_sum - double_digit_sum)
            return true;

        return false;
    }
};
