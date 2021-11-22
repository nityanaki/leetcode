class Solution {
public:
    string intToRoman(int num) {
        string output = "";
        int temp = 0;
        if(num >= 1000) {
            while(num / 1000 > 0){
                output += "M";
                num -= 1000;
            }
        }
        if(num >= 900) {
            num -= 900;
            output += "CM";
        }
        if(num >= 500) {
            num -= 500;
            output += "D";
        }
        if(num >= 400) {
            num -= 400;
            output += "CD";
        }
        if(num >= 100) {
            while(num / 100 > 0){
                output += "C";
                num -= 100;
            }
        }
        if (num >= 90) {
            num -= 90;
            output += "XC";
        }
        if (num >= 50) {
            num -= 50;
            output += "L";
        }
        if(num >= 40) {
            num -= 40;
            output += "XL";
        }
        if(num >= 10) {
            while(num / 10 > 0){
                output += "X";
                num -= 10;
            }
        }
        if(num >= 9) {
            num -= 9;
            output += "IX";
        }
        if(num >= 5) {
            num -= 5;
            output += "V";
        }
        if(num >= 4) {
            num -= 4;
            output += "IV";
        }
        if(num >= 1) {
            while(num > 0){
                output += "I";
                num -= 1;
            }
        }
        return output;
    }
};

// improvements: use vector or unordered map instead
