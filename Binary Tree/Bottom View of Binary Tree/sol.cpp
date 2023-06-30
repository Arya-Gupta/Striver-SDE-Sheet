/*
Time Complexity - Since it takes logN time to insert each of the N nodes into a map, time taken is O(N*log N).

Space Complexity - Since we are storing the nodes in a queue, space taken is O(N).

Explanation - This question is a variation of https://github.com/Arya-Gupta/450DSA/blob/main/Binary%20Trees/Top%20View%20of%20Binary%20Tree/Iterative%20solution
We measure height of the nodes along the X axis. Going right increases the height by 1 and going left decreases the height by 1. The root node is at 0 height.
We store each {height, node} pair in a ordered map so that a new node we encounter at the same height overwrites the existing node in the map.
Thus we can maintain 1 node at each unique height which gives us the bottom view.
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<int, Node*>> Q;
        map<int, Node*> mp;
        Q.push({0, root});
        
        while(!Q.empty()){
            pair<int, Node*> p = Q.front();
            Q.pop();
            mp[p.first] = p.second;
            if(p.second->left) Q.push({p.first - 1, p.second->left});
            if(p.second->right) Q.push({p.first + 1, p.second->right});
        }
        
        vector<int> ans;
        for(auto i : mp) ans.push_back(i.second->data);
        return ans;
    }
};