# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        int size = my_sizeof(arr);
        vector<int> largestNumbers;
        
        if (size == 0) return largestNumbers;
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < size; i++) {
            minHeap.push(arr[i]);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        while (!minHeap.empty()) {
            largestNumbers.push_back(minHeap.top());
            minHeap.pop();
        }
        
        return largestNumbers;
    }
};