int balancedSum(vector<int> arr) {
    int pivot = -1;

    vector<int> leftSum(arr.size(), 0);
    leftSum[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        leftSum[i] += arr[i] + leftSum[i - 1];;
    }

    vector<int> rightSum(arr.size(), 0);
    rightSum[arr.size() - 1] = arr[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--) {
        rightSum[i] = arr[i] + rightSum[i + 1];
    }

    for (int i = 0; i < leftSum.size(); i++) {
        if (leftSum[i] == rightSum[i]) {
            pivot = i;
        }
    }

    return pivot;
}
