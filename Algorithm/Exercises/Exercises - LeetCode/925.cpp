class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.length() < name.length()) return false;
        int typedPtr = 0;
        int namePtr = 0;
        while (typedPtr < typed.length() && namePtr < name.length()) {
            if (name[namePtr] == typed[typedPtr]) {
                char c = name[namePtr];
                int typedC = 0;
                int nameC = 0;
                while (typed[typedPtr] == c) {
                    typedPtr++;
                    typedC++;
                }
                while (name[namePtr] == c) {
                    namePtr++;
                    nameC++;
                }
                if (nameC > typedC) return false;
            } else {
                return false;
            }
        }
        return typedPtr == typed.length() && namePtr == name.length();
    }
};
