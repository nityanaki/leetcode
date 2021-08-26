class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //go to last index in vector, add 1 if it's not 9
        // 9 + 1
        //else, go to the previous index, add 1 if it's not 9,
        //keep going through the vector
        
        //issue: 999 + 1 = 1000 (add extra digit?)
        //add digit at the beginning
        
        //find the last digit/element in digits
        int ld = digits.at(digits.size()-1);
        //if statement to see if it's = 9 or not
        for (int i = digits.size()-1; i >=0; --i) {
            if (digits.at(i)!=9) {
                digits.at(i)++;
                return digits;
            } else {
                digits.at(i) = 0;
                //189 - > 190
            }
        }
        
        //from here, all numbers in digits seem to be 9 if it didn't return
        //999 - > 000
        digits.insert(digits.begin(), 1);
        return digits;
        
            //it's not 9: add 1 and return
            //it is 9: replace digit with 0, reduce index, go through while loop until we reach number that's not 9
            //if this isn't possible, keep counter to see if we need extra digit
        
        //returning the digits vector
    }
};
