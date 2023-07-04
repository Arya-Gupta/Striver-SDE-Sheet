/*
Time Complexity - Level order traversal takes O(N) time.
 
Space Complexity - Storing nodes in queue takes O(N) space.

Explanation - We index left node as 2*i + 1 and right node as 2*i + 2 so that the nodes are indexed in such a manner that missing nodes are also counted.
We subtract the min value of the current level from the index of the node to prevent integer overflow. 
Thus instead of storing the index of the node, we store the index of the node - min value of the current level.
Thus the levels are indexed as [0], [1, 2], [1, 2, 3, 4], [1, 2, 3, 4, 5, 6, 7, 8] and so on.     
Thus at any level, last node value - first node value + 1 will give us width of that level. 
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});

        while(!Q.empty()){
            int first, last;
            int n = Q.size();
            int minVal = Q.front().second; // min value of the current level

            for(int i = 0; i < n; i++){
                TreeNode* currNode = Q.front().first;
                int val = Q.front().second - minVal; // subtracted to prevent integer overflow
                Q.pop();
                if(i == 0) first = val;
                if(i == n - 1) last = val;
                if(currNode->left) Q.push({currNode->left, (long long) 2 * val + 1}); 
                if(currNode->right) Q.push({currNode->right, (long long) 2 * val + 2});
            }

            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};