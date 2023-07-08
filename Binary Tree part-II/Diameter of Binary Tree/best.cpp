/*
Time Complexity - Performing bfs takes O(N) time.

Space Complexity - Stack space required is O(N) due to recursion.

Explanation - As we perform bfs, we calculate the the diameter of each node. This helps us avoid calculating diameter of each node individually.
*/

class Solution {
public:
    int height(TreeNode* root, int &diameter) {
        if(!root) return 0;
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return max(lh, rh) + 1; // returning height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};