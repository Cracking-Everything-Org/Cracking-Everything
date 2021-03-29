using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    int nextNonDup = 1;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[nextNonDup - 1] != arr[i]) {
        arr[nextNonDup] = arr[i];
        nextNonDup++;
      }
    }
    return nextNonDup;
  }
};
