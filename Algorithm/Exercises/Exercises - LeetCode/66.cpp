class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int index = digits.size()-1;
        while(carry>0 ){
            if (index<0) {
                digits.insert(digits.begin(),1);
                break;
            }
            if (digits[index] + 1 < 10){
                digits[index]++;
                carry--;
            } else {
                digits[index] = 0;
                index--;
            }
        }
        return digits;
    }
};
