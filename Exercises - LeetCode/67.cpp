class Solution {
public:
    string addBinary(string a, string b) {
        bitset<128> x{a};
        bitset<128> y{b};
        while (y.any()) {
            bitset<128> temp = x^y;
            y = (x&y) << 1;
            x = temp;
        }
        string s = x.to_string();

        s = s.erase(0, s.find_first_not_of('0'));
        if (!s.size()) return "0";
        return s;

    }
};
