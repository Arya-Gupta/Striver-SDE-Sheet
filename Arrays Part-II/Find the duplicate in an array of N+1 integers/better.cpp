/*
Time Complexity - Iterating through the array takes O(N) time.

Space Complexity - Creating an array of size N takes O(N) space.

Explanation - We hash the values of the array in a frequency array and if we find a value which is already present in the frequency array, we return that value.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans;
        vector<int> freq(n, 0);
        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == 0) freq[nums[i]]++;
            else ans = nums[i];
        }
        return ans;
    }
};