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
    void inorder(TreeNode* root, int & counter, int k,int& kthsmallest){
        if(!root || counter>=k)return;

        //Traversing in the left subtree
        inorder(root->left,counter,k,kthsmallest);

        counter++;

        if(counter==k){
            kthsmallest = root->val;
            return;

        }
        inorder(root->right,counter,k,kthsmallest);

    }
    int kthSmallest(TreeNode* root, int k) {
        int kthsmallest = INT_MIN;
        int counter=0;

        inorder(root,counter,k,kthsmallest);
        return kthsmallest;
    }
};