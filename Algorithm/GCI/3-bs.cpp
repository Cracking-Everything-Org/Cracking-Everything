class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
    int n = letters.size();
    if (key < letters[0] || key > letters[n - 1]) {
      return letters[0];
    }
    int left = 0;
    int right = letters.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (letters[mid] > key) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return letters[left % n];
  }
};