class Solution {
public: 
void findCombinations(int indx, int target,vector<int> &arr,vector<vector<int>> &ans,vector<int>&ds){
    if(indx == arr.size()){
        if(target ==0){
            ans.push_back(ds);
        }
        return;
    }
    //now picking up the element
    if(arr[indx] <= target){
        ds.push_back(arr[indx]);
        findCombinations(indx,target-arr[indx],arr,ans,ds);
        ds.pop_back();
    }
    findCombinations(indx+1,target,arr,ans,ds);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0,target,candidates,ans,ds);
        return ans;

    }
};