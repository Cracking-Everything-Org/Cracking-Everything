class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        if (!jewels.length() || !stones.length()) return -1;
        
        int jewelsFound = 0;
        
        vector<bool> jewelsList(52);
        for (char jewel : jewels) {
            if (jewel - 'a' < 0) {
                jewelsList[jewel - 'A' + 26] = true;
            } else {
                jewelsList[jewel - 'a'] = true;
            }
        }
        
        for (char stone : stones) {
            if (stone - 'a' < 0) {
                jewelsFound += jewelsList[stone - 'A' + 26] ? 1 : 0;
            } else {
                jewelsFound += jewelsList[stone - 'a'] ? 1 : 0;
            }
        }
        
        return jewelsFound;
    }
};