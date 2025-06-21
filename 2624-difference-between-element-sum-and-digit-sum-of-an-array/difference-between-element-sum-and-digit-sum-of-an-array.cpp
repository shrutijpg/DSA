class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        long long eleSum=0;
        long long digiSum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            
                eleSum += nums[i];
                int num= nums[i];
                while (num > 0) {
                    int digit = num % 10;   // get last digit
                    digiSum += digit;         // add to total
                    num /= 10;              // remove last digit
                }
            
        }
        int diff = abs(eleSum-digiSum);
        return diff;
    }
};