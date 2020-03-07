Problem Statement #
Given a binary matrix representing an image, we want to flip the image horizontally, then invert it.

To flip an image horizontally means that each row of the image is reversed. For example, flipping [0, 1, 1] horizontally results in [1, 1, 0].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [1, 1, 0] results in [0, 0, 1].

Example 1:

Input: [
  [1,0,1],
  [1,1,1],
  [0,1,1]
]
Output: [
  [0,1,0],
  [0,0,0],
  [0,0,1]
]
Explanation: First reverse each row: [[1,0,1],[1,1,1],[1,1,0]]. Then, invert the image: [[0,1,0],[0,0,0],[0,0,1]]

Example 2:

Input: [
  [1,1,0,0],
  [1,0,0,1],
  [0,1,1,1],
  [1,0,1,0]
]
Output: [
  [1,1,0,0],
  [0,1,1,0],
  [0,0,0,1],
  [1,0,1,0]
]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]. Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]


vector<vector<int>> flipAndInvertImage(vector<vector<int>> arr) {
    int s = arr[0].size();
    for (int row = 0; row < arr.size(); row++) {
        for (int col = 0; col < (s + 1) / 2; ++col) {
            int tmp = arr[row][col] ^ 1;
            arr[row][col] = arr[row][s - 1 - col] ^ 1;
            arr[row][s - 1 - col] = tmp;
        }
    }
    return arr;
  }

  static void print(const vector<vector<int>> arr) {
    for(int i=0; i < arr.size(); i++) {
      for (int j=0; j < arr[i].size(); j++) {
        cout << arr[i][j] << " ";
      }
      cout << "\n";
    }
  }

Time Complexity #
The time complexity of this solution is O(n) as we iterate through all elements of the input.

Space Complexity #
The space complexity of this solution is O(1).
