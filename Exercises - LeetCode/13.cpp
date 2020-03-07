class Solution {
public:
    int romanToInt(string s) {
        int nums[89];
        nums['I'] = 1;
        nums['V'] = 5;
        nums['X'] = 10;
        nums['L'] = 50;
        nums['C'] = 100;
        nums['D'] = 500;
        nums['M'] = 1000;
        int result = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i + 1 < s.length() && nums[s[i+1]] > nums[s[i]])
                result -=  nums[s[i]];
            else
                result += nums[s[i]];
        }
        return result;
    }
};
