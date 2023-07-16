/*
Time Complexity - Dfs takes O(N) time.

Space Complexity - Space taken is O(H) stack space due to recursion or O(1).

Explanation - Finding the height of each node individually is a repetitive task. Instead of doing this, we can find the height of each node during dfs traversal.
We add a check for each node to figure out if the left subtree and right subtree are balanced or not. 
If they are balanced, we return the height of the node. 
If they aren't, we simply return -1.

If we encounter a -1 while calculating the leftHeight or rightHeight of any node, we know that the tree has an unbalanced subtree and therefore the entire tree must be unbalanced.
Thus we do not calculate any further and simply return -1 to the parent node.
*/

class Solution {
public:
    int dfsHeight(TreeNode* root){
        if(!root) return 0;

        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};