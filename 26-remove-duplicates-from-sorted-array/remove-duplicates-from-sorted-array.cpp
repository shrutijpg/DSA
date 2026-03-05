class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i = 1;
        int j=0;

        while(i<n){
            if(nums[i] == nums[i-1]){
                i++;
                continue;

            }
            nums[j+1] = nums[i];
            j++;
            count++;
            i++;

        }
        return count+1;
    }
};