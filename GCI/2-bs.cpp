class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    if (key > arr[arr.size() - 1]) {
      return -1;
    }
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == key) {
        return mid;
      } else if (arr[mid] > key) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;  
  }
};