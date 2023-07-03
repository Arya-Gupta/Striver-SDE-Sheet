/*
Time Complexity - Since we are iterating through the entire string, time taken is O(N).

Space Complexity - Since storing values of roman characters in map takes constant space, space taken is O(1).

Explanation - Store values in map for easy access. 
If next character value is less than current like in case of 'IV' we subtract val[s[i]] from ans.
Else we add val[s[i]] to ans.
*/

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        // storing the values in a map
        unordered_map<char, int> val = { 
            { 'I' , 1 },
            { 'V' , 5 },
            { 'X' , 10 },
            { 'L' , 50 },
            { 'C' , 100 },
            { 'D' , 500 },
            { 'M' , 1000 } 
        };

        for(int i = 0; i < s.length(); i++){
            if(val[s[i]] < val[s[i + 1]]) ans -= val[s[i]];
            else ans += val[s[i]];
        }

        return ans;
    }
};