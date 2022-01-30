class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int closest = binarySearch(arr, k, x);
        int low = closest;
        int high = closest;
        while (high - low + 1 < k && low > 0 && high < arr.size() - 1) {
            //  If there is a tie, the smaller elements are always preferred
            if (abs(arr[low - 1] - x) <= abs(arr[high + 1] - x)) {
                low--;
            } else {
                high++;
            }
        }

        while (high - low + 1 < k) {
            if (low > 0) {
                low--;
            } else {
                high++;
            }
        }

        vector<int> ans;
        while (low <= high) {
            ans.push_back(arr[low]);
            low++;
        }
        return ans;
    }


    int binarySearch(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        int minDiff = INT_MAX;
        int closestIndex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (abs(arr[mid] - x) < minDiff) {
                minDiff = abs(arr[mid] - x);
                closestIndex = mid;
            }
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return closestIndex;
    }
};
