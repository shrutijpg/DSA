class Solution {

public:
    void help(int i , int k,int sumTillNow,int n,vector<int>&subset,vector<vector<int>>&ans){
        // Base case: if k is less than 0 or sum exceeds n, return
        if (k < 0 || sumTillNow > n) return;

        // If we have already picked k numbers and their sum is n, add the subset to the answer
        if (k == 0 && sumTillNow == n) {
            ans.push_back(subset);
            return;
        }
        if(i>9)return;



        //picking the element
        subset.push_back(i);
        help(i+1,k-1,sumTillNow+i,n,subset,ans);
        subset.pop_back();


        //ignoring the element
        help(i+1,k,sumTillNow,n,subset,ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        help(1,k,0,n,subset,ans);
        return ans;

        
    }
};