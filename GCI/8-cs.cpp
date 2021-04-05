class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    vector<int> missingNumbers;
    unordered_set<int> extraNumbers;
    for (i = 0; i < nums.size() && missingNumbers.size() < k; i++) {
      if (nums[i] != i + 1) {
        missingNumbers.push_back(i + 1);
        extraNumbers.insert(nums[i]);
      }
    }

    // add the remaining missing numbers
    for (i = 1; missingNumbers.size() < k; i++) {
      int candidateNumber = i + nums.size();
      // ignore if the array contains the candidate number
      if (extraNumbers.find(candidateNumber) == extraNumbers.end()) {
        missingNumbers.push_back(candidateNumber);
      }
    }

    return missingNumbers;
  }