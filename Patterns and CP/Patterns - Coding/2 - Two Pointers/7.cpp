using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
 public:
  static void sort(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    for (int i = 0; i <= high;) {
      if (arr[i] == 0) {
        swap(arr[i], arr[low]);
        i++;
        low++;
      } else if (arr[i] == 1) {
        i++;
      } else {
        swap(arr[i], arr[high]);
        high--;
      }
    }
  }
};
