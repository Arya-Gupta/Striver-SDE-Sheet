/*
Time Complexity - Since we visit each node, time taken is O(N).

Space Complexity - Morris traversal helps us avoid recursion, hence space taken is O(1).

Explanation - In morris traversal, we use the concept of threaded binary tree to avoid using extra stack space used in the regular recursive approach.
Case 1 - there is no left node
Print the current node and then visit the right subtree.
Case 2 - there is a left node 
We need to visit the left subtree, but first we must create a thread before moving away from currNode so that we can travel back to it.
Find the inorder predecessor of the current node. (we take care not to use thread if it exists)
We can create a thread from this node to the current node to come back to our current node after printing the left subtree.
    Case 2a) Thread doesn't already exist => left subtree hasn't been visited
    We visit the left subtree and create the thread.
    Case 2b) Thread already exists => We have traversed the left subtree and we are back at currNode
    We delete the thread, print our currNode and then move to our right subtree.
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
                    ans.push_back(currNode->val);
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