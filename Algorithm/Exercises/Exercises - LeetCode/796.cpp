class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        if (!A.size()) return true;
        for (int i = 0; i < B.length(); i++) {
            if (A[0] == B[i]) {
                if(tryRotation(A, B, i)) return true;
            }
        }
        return false;
    }

    bool tryRotation(string A, string B, int position) {
        int size = B.size();
        int current = 0;
        for (int i = 0; i < size; i++) {
            if (A[current] != B[(position + i) % size]) return false;
            current++;
        }
        return true;
    }
};
