/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        long long ans =0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0}); // storing the root and the intial index 

        while(!q.empty()){
            int size = q.size();
            long long mmin = q.front().second; //To make the id again starting from zero (it stores the minimal index right now)
            long long first,last;
            for(int i =0;i<size;i++){
                long long cur_id = q.front().second -mmin; //Ensure that the current index is reduced again inorder to avoid overflow

                TreeNode* node = q.front().first;
                q.pop();

                if(i==0) first = cur_id;
                if(i == size-1) last = cur_id;
                if(node->left){
                    q.push({node->left,((cur_id*2)+1)});
                }
                if(node->right){
                    q.push({node->right,((cur_id*2)+2)});
                }



            }
            ans = max(ans,last-first+1);


        }
        return ans;
    }
};