Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9]

vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    // TODO: Write your code here
    int first = 0;
    int second = n - 1;
    int highest = n - 1;
    while(first<=second){
      int firstSquare = arr[first] * arr[first];
      int secondSquare = arr[second] * arr[second];
      if (secondSquare > firstSquare) {
        squares[highest] = secondSquare;
        second--;
      } else {
        squares[highest] = firstSquare;
        first++;
      }
      highest--;
    }

    return squares;
  }

  Time complexity #
  The time complexity of the above algorithm will be O(N) as we are iterating the input array only once.

  Space complexity #
  The space complexity of the above algorithm will also be O(N); this space will be used for the output array.
