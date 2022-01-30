class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {

        vector<int> ans;

        int pointerA = 0;
        int pointerB = 0;
        int pointerC = 0;

        while (pointerA < arr1.size() && pointerB < arr2.size() && pointerC < arr3.size()) {
            if (arr1[pointerA] == arr2[pointerB] && arr1[pointerA] == arr3[pointerC]) {
                ans.push_back(arr1[pointerA]);
                pointerA++;
                pointerB++;
                pointerC++;
            } else {
                int minimum = min(min(arr1[pointerA], arr2[pointerB]), arr3[pointerC]);
                if (arr1[pointerA] == minimum) {
                    pointerA++;
                } else if (arr2[pointerB] == minimum) {
                    pointerB++;
                } else {
                    pointerC++;
                }
            }
        }

        return ans;

    }
};
