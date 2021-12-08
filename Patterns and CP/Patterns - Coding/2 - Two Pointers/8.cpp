using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class QuadrupleSumToTarget {
 public:
  static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> quadruplets;
    for (int i = 0; i < arr.size() - 3; i++) {
      if (i > 0 && arr[i] == arr[i - 1]) {  // skip same element to avoid duplicate quadruplets
        continue;
      }
      for (int j = i + 1; j < arr.size() - 2; j++) {
        if (j > i + 1 &&
            arr[j] == arr[j - 1]) {  // skip same element to avoid duplicate quadruplets
          continue;
        }
        searchPairs(arr, target, i, j, quadruplets);
      }
    }
    return quadruplets;
  }

 private:
  static void searchPairs(const vector<int> &arr, int targetSum, int first, int second,
                          vector<vector<int>> &quadruplets) {
    int left = second + 1;
    int right = arr.size() - 1;
    while (left < right) {
      int sum = arr[first] + arr[second] + arr[left] + arr[right];
      if (sum == targetSum) {  // found the quadruplet
        quadruplets.push_back({arr[first], arr[second], arr[left], arr[right]});
        left++;
        right--;
        while (left < right && arr[left] == arr[left - 1]) {
          left++;  // skip same element to avoid duplicate quadruplets
        }
        while (left < right && arr[right] == arr[right + 1]) {
          right--;  // skip same element to avoid duplicate quadruplets
        }
      } else if (sum < targetSum) {
        left++;  // we need a pair with a bigger sum
      } else {
        right--;  // we need a pair with a smaller sum
      }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {4, 1, 2, -1, 1, -3};
  auto result = QuadrupleSumToTarget::searchQuadruplets(vec, 1);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {2, 0, -1, 1, -2, 2};
  result = QuadrupleSumToTarget::searchQuadruplets(vec, 2);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
