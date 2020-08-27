class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size();
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (target >= letters[middle]) {
                left = middle + 1;
            } else
                right = middle;
        }
        return letters[left % letters.size()];
    }
};
