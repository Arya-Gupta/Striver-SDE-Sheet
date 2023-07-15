/*
Time Complexity - Time taken to traverse the array is O(N).

Space Complexity - Since we do not require extra space, space complexity is O(1).

Explanation - https://www.youtube.com/watch?v=nP_ns3uSh80
We solve this problem using Moore's Voting Algorithm.
We take two variables, one to store the element and the other to store the count.
We traverse the array and if the count is 0, we store the current element in the element variable and increment the count.
If the count is not 0, we check if the current element is equal to the element variable. If it is, we increment the count, else we decrement the count.
At the end, the element variable will contain the majority element.

The intuition behind this algorithm is that if there is a majority element in the array, its count can never be 0 because the majority element is the element that appears more than ⌊n / 2⌋ times.

If there IS a majority element, then it will be this element that we obtain at the end of the process.
This process works because in the question it is specified that we can assume that the majority element always exists in the array.

There may be an array where NO majority element exists. 
In case of such a question, we need to iterate through the array to confirm if the element we have obtained is actually the majority element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el, cnt = 0;
        for(auto i : nums){
            if(cnt == 0){
                el = i;
                cnt++;
            }
            else if(el == i){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return el;
    }
};