Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.

vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    vector<vector<int>> quadruplets;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    int left = 0;
    for(int i = 0; i<arr.size()-4; i++){
      for(int j = i+1; j<arr.size()-3; j++){
        left = j+1;
        while(arr[i] == arr[j]){
          i++;
          j++;
        }
        if(arr[i]+arr[j]<target){
          int targetSum = target - arr[i] - arr[j];
          vector<int> current;
          current.push_back(arr[i]);
          current.push_back(arr[j]);
          findPair(arr, left, targetSum, current, quadruplets);
        }
      }
    }
    return quadruplets;
  }

  static void findPair (vector<int> &arr, int left, int targetSum,vector<int> &current, vector<vector<int>> &quadruplets){
    int high = arr.size()-1;
    while(left<high){
      if(arr[left] + arr[high] == targetSum){
        current.push_back(arr[left]);
        current.push_back(arr[high]);
        quadruplets.push_back(current);
        break;
      } else {
        if(arr[left] + arr[high] < targetSum){
          left++;
        } else {
          high--;
        }
      }
    }
  }


Time complexity #
Sorting the array will take O(N*logN)O(N∗logN). Overall searchQuadruplets() will take O(N * logN + N^3), which is asymptotically equivalent to O(N^3).

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for sorting.
