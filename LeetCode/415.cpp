class Solution {
public:
    string addStrings(string num1, string num2) {
        long sumResult = 0;
        for(int i=num1.length()-1; i>=0; i--){
            sumResult += (num1[i]-'0')*(pow(10,num1.length()-1-i));
        }
        for(int i=num2.length()-1; i>=0; i--){
            sumResult += (num2[i]-'0')*(pow(10,num2.length()-1-i));
        }
        return to_string(sumResult);
    }
};
