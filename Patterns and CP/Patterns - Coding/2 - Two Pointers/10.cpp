using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ShortestWindowSort {
 public:
  static int sort(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    // find the first number out of sorting order from the beginning
    while (low < arr.size() - 1 && arr[low] <= arr[low + 1]) {
      low++;
    }

    if (low == arr.size() - 1) {  // if the array is sorted
      return 0;
    }

    // find the first number out of sorting order from the end
    while (high > 0 && arr[high] >= arr[high - 1]) {
      high--;
    }

    // find the maximum and minimum of the subarray
    int subarrayMax = numeric_limits<int>::min(), subarrayMin = numeric_limits<int>::max();
    for (int k = low; k <= high; k++) {
      subarrayMax = max(subarrayMax, arr[k]);
      subarrayMin = min(subarrayMin, arr[k]);
    }

    // extend the subarray to include any number which is bigger than the minimum of the subarray
    while (low > 0 && arr[low - 1] > subarrayMin) {
      low--;
    }
    // extend the subarray to include any number which is smaller than the maximum of the subarray
    while (high < arr.size() - 1 && arr[high + 1] < subarrayMax) {
      high++;
    }

    return high - low + 1;
  }
};

int main(int argc, char* argv[]) {
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 3}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{3, 2, 1}) << endl;
}