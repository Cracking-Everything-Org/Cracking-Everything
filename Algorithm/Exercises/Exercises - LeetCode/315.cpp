class Solution {
public:
    struct Item {
        int value;
        int index;
        Item(int val, int idx) {
            value = val;
            index = idx;
        }
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<Item> items(n);
        for (int i = 0; i < n; i++) {
            items[i] = Item(nums[i], i);
        }
        vector<int> count(n);
        mergeSort(items, 0, n - 1, count);
        
        return count;
    }
    
    void mergeSort(vector<Item> items, int lo, int hi, vector<int> count) {
        if (lo > hi) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(items, lo, mid, count);
        mergeSort(items, mid + 1, hi, count);
        merge(items, lo, mid, mid + 1, hi, count);
    }
    
    void merge(vector<Item> items, int lo, int loEnd, int hi, int hiEnd,  vector<int> count) {
        int m = hiEnd - lo + 1;
        vector<Item> sorted(m);
        int index = 0;
        int loPtr = lo, hiPtr = hi;
        int rightCounter = 0;
        
        while (loPtr <= loEnd && hiPtr <= hiEnd) {
            if (items[hiPtr].value < items[loPtr].value) {
                rightCounter++;
                sorted[index++] = items[hiPtr++];
            } else {
                count[items[loPtr].index] += rightCounter;
                sorted[index++] = items[loPtr++];
            }
        }
        
        while (loPtr <= loEnd) {
            count[items[loPtr].index] += rightCounter;
            sorted[index++] = items[loPtr++];
        }
        
        while (hiPtr <= hiEnd) {
            sorted[index++] = items[hiPtr++];
        }
        
        for (int i = 0; i < m; i++) {
            items[i + lo] = sorted[i];
        }
    }
};