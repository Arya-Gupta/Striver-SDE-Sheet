/*
Time Complexity - Iterating through the array takes O(N) time.

Space Complexity - O(1) as we are not using any extra space.

Explanation - Same approach as: https://leetcode.com/problems/majority-element/
Since we have to find the elements that appears more than N/3 times in the array, we can have at max 2 such elements.
Because if say n = 10, then the majority element has to occur atleast 4 times. So, 2 such elements can occur at max.

This question doesn't specify if there necessarily exists a majority element in our array.
Unlike the previous question, we have to manually check to confirm if el1 and el2 are actually majority elements or not.

We also have checks for i != el2 and i != el1 because we might end up with the same element in both el1 and el2.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1, el2, cnt1 = 0, cnt2 = 0;

        for(auto i : nums){
            if(cnt1 == 0 && i != el2){
                el1 = i;
                cnt1++;
            }
            else if(cnt2 == 0 && i != el1){
                el2 = i;
                cnt2++;
            }
            else if(i == el1){
                cnt1++;
            }
            else if(i == el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = 0, cnt2 = 0;

        for(auto i : nums){
            if(i == el1) cnt1++;
            else if(i == el2) cnt2++;
        }
        
        if(cnt1 > floor(nums.size() / 3)) ans.push_back(el1);
        if(cnt2 > floor(nums.size() / 3)) ans.push_back(el2);
        return ans;
    }
};