class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    bool isAscending = arr[left] < arr[right];
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == key) {
        return mid;
      }
      if (isAscending) {  // ascending order
        if (key < arr[mid]) {
          right = mid - 1;    // the 'key' can be in the first half
        } else {            // key > arr[mid]
          left = mid + 1;  // the 'key' can be in the second half
        }
      } else {  // descending order
        if (key > arr[mid]) {
          right = mid - 1;    // the 'key' can be in the first half
        } else {            // key < arr[mid]
          left = mid + 1;  // the 'key' can be in the second half
        }
      }
    }
    return -1; 
  }
};