class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int counter = 0;
        for(auto i : nums) {
            if(to_string(i).length()%2==0) counter++;
        }
        return counter;
    }
};
