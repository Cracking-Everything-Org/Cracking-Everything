using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    int left = 0;
    int right = arr.size() - 1;
    int current = arr.size() - 1;

    while (left < right) {
      if (pow(arr[left], 2) >= pow(arr[right], 2)) {
        squares[current] = pow(arr[left], 2);
        left++;
      } else {
        squares[current] = pow(arr[right], 2);
        right--;
      }
      current--;
    }
    return squares;
  }
};
