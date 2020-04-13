class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<int, int> ht;
        ht[0] = 0;
        ht[1] = 1;
        ht[6] = 9;
        ht[8] = 8;
        ht[9] = 6;

        for (int i = 0; i <= num.length() / 2 ; i++) {
            if (ht.find(num[i] - '0') == ht.end()) {
                return false;
            }
            int a = ht[num[i] - '0'];
            int b = (num[num.length() - 1 - i]) - '0';
            if (ht[num[i] - '0'] != (num[num.length() - 1 - i]) - '0') {
                return false;
            }
        }
        return true;
    }
};
