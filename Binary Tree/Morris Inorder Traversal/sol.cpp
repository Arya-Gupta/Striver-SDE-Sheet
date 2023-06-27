/*
Time Complexity - Since we visit each node, time taken is O(N).

Space Complexity - Morris traversal helps us avoid recursion, hence space taken is O(1).

Explanation - There is only a single line changed from morris inorder traversal.
*/

class Solution {
public:
    TreeNode* giveInorderPredecessor(TreeNode* currNode){
        TreeNode* temp = currNode->left;
        // we go as right as possible but avoid using the thread to return back to currNode
        while(temp->right && temp->right != currNode) temp = temp->right;
        return temp;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* currNode = root;
        while(currNode){
            // left node doesn't exist
            if(!currNode->left){
                ans.push_back(currNode->val);
                currNode = currNode->right;
            }
            // left node exists
            else{
                TreeNode* inorderPredecessor = giveInorderPredecessor(currNode);
                // left subtree already visited
                if(inorderPredecessor->right){
                    inorderPredecessor->right = NULL; // remove thread
                    ans.push_back(currNode->val); // single line changed from morris inorder traversal
                    currNode = currNode->right;
                }
                // left subtree not visited
                else{
                    inorderPredecessor->right = currNode; // create thread
                    currNode = currNode->left;
                }
            }
        }
        return ans;
    }
};