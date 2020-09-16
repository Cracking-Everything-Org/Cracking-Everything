#include <unordered_map>

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        if (arr.size() < k*m) return false;
        int startWindow = 0;
        for (int endWindow = 0; endWindow < arr.size(); endWindow++) {
            if (endWindow - startWindow + 1 >= k*m) {
                //cout << "startWindow: " << startWindow << endl;
                //cout << "endWindow: " << endWindow << endl;
                if (check(arr, startWindow, endWindow, m, k)) return true;
                startWindow++;
            }
        }
        return false;
    }

    bool check(vector<int>& arr, int start, int end, int m, int k) {
        string pattern = "";
        for (int i = start; i < start + m; i++) {
            pattern += to_string(arr[i]);
        }
        //cout << "pattern: " + pattern << endl;
        for (int i = 0; i < k; i++) {
            string current = "";
            for (int j = start + (i*m); j < start + (i*m) + m; j++) {
                current += to_string(arr[j]);
            }
            //cout << "current: " + current << endl;
            if (current != pattern) return false;
        }
        return true;
    }
};
