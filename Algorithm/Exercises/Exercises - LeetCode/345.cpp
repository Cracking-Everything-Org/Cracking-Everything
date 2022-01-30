class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, bool> ht =
        {{'a',true},
        {'e',true},
        {'i',true},
        {'o',true},
        {'u',true}};

        int leftPtr = 0;
        int rightPtr = s.length() - 1;
        while (leftPtr < rightPtr) {
            while (ht.find(tolower(s[leftPtr])) == ht.end() && leftPtr < rightPtr) {
                leftPtr++;
            }
            while (ht.find(tolower(s[rightPtr])) == ht.end() && leftPtr < rightPtr) {
                rightPtr--;
            }
            swap(s[leftPtr], s[rightPtr]);
            leftPtr++;
            rightPtr--;
        }
        return s;
    }
};
