class Solution {
public:
    bool checkValidString(string s) {
        // necesito mantener un balance de que no hayan más high que low
        int low = 0; // lo uso para los (
        int high = 0; // lo uso para )
        for (int i = 0; i < s.length(); i++) {
            low += s[i] == '(' ? 1 : -1;
            high += s[i] != ')' ? 1 : -1;
            if (high < 0) {
                break;
            }
            low = max(low, 0);
        }
        return low == 0;
    }
};
