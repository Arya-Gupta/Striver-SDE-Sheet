/*
Time Complexity -

Space Complexity -

Explanation - https://www.youtube.com/watch?v=f2ic2Rsc9pU&t=32s
*/

class Solution {
public:
    void findPermutations(vector<int> &nums, vector<vector<int>> &perm, int pos){
        int n = nums.size();
        if(pos == n){
            perm.push_back(nums);
            return;
        }
        for(int i = pos; i < n; i++){
            swap(nums[pos], nums[i]);
            findPermutations(nums, perm, pos + 1);
            swap(nums[pos], nums[i]); // reswap
        }
    }

    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> perm;
        findPermutations(nums, perm, 0);
        
        // for(int i = 0; i < perm.size(); i++){
        //     for(int j = 0; j < perm[0].size(); j++){
        //         cout << perm[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // find nums in perm and return next permutation
        for(int i = 0; i < perm.size(); i++){
            if(nums == perm[i]){
                nums = perm[i + 1];
                break;
            }
        }
    }
};