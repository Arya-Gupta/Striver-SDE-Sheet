/*
Time Complexity - We traverse N nodes and for each we calculate depth. Thus time taken is O(N^2).

Space Complexity - O(N) stack space is used due to recursion.

Explanation - We perform dfs traversal and calculate the diameter of each node and thus the maximum diameter.
Diameter of a node = left depth + right depth
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return max(lh, rh) + 1; 
    }
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        maxDiameter = max(maxDiameter, maxDepth(root->left) + maxDepth(root->right));
        return maxDiameter;
    }
};