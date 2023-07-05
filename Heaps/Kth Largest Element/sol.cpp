/*
Time Complexity - Since we are using n integers to create min heap of size k, time taken is O(Nlogk).

Space Complexity - Since we are creating a heap of k elements, space taken is O(k).

Explanation - We store the first k elements in the min heap and pop off any excess elements. The top element is the kth greatest element.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for(auto i : nums){
            minh.push(i);
            if(minh.size() > k) minh.pop();
        }
        return minh.top();
    }
};