class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        
        
        // create vector with 26 chars and with values of 0
        vector<int> letters(128, 0);
        // create a maxlen variable
        int maxlen = 0;
        
        int start = 0;
        //don't think the end pointer was necessary (could use i instead)
        int end = 1;
        
        // loop through the inputted string
        for (int i = 0; i < s.length(); i++) {
            // search if current letter has been used already
            // first, find out what the value of the letter would be
            int val = int(s[i]);
            if (letters[val] == 1) {
                // fill(letters.begin(), letters.end(), 0);
                letters[val] = 0;
                // change start appropriately to reflect where to go past the duplicate letter
                
                while (s[start] != s[i]) {
                    letters[int(s[start])] = 0;
                    ++start;
                }
                ++start;
                
            }
            int len = end - start;
            letters[val] = 1;
            
            if (len > maxlen) {
                maxlen = len;
            }
            
            ++end;
        }
        
        return maxlen;
        
    }
};

// brute force solution:
// store a longest string variable
// store a temp curr string variable
// each time you get to another letter, compare with previous string
// p inefficient: Can have O(N^2) efficiency

// better solution:
// create a vector with indices representing letters of alphabet
// at each index, will have 0 or 1 values representing whether the letter has been used or not

// consider edge cases
// empty string: should just end the loop, and the output will continue to be 0
