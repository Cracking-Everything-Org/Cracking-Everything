using namespace std;

#include <iostream>
#include <vector>
#include <math.h>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    vector<int> squares(arr.size(), 0);

    int left = 0;
    int right = arr.size() - 1;
    int end = arr.size() - 1;
    while (left <= right) {
      int leftSquare = pow(arr[left], 2);
      int rightSquare = pow(arr[right], 2);
      if (leftSquare > rightSquare) {
        squares[end] = leftSquare;
        left++;
      } else {
        squares[end] = rightSquare;
        right--;
      } 
      end--;
    }
    return squares;
  }
};
