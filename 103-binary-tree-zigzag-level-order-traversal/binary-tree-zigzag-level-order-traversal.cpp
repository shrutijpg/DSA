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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;

        }

        queue<TreeNode*> NodesQueue;
        NodesQueue.push(root);

        bool LeftToRight = true;  // Flag

        while(!NodesQueue.empty()){
            int size = NodesQueue.size();
            vector<int> row(size);

            for(int i=0;i<size;i++){
                TreeNode* node = NodesQueue.front();
                NodesQueue.pop();


                //finding positions to fill the nodes va;lue
                int index = (LeftToRight) ? i: (size-1-i); // if flag true then insert in the same order if flag is flase then insert in the reverse order

                row[index] = node->val;
                if(node->left){
                    NodesQueue.push(node->left);
                }

                if(node->right){
                    NodesQueue.push(node->right);
                }

                
            }
            LeftToRight = !LeftToRight;
            result.push_back(row);
            
        }
        return result;

    }
};