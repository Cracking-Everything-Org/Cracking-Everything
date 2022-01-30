class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<pair<double, pair<int,int> > > maxHeap;
        for (int i=0; i<A.size(); i++) {
            for (int j=i+1; j<A.size(); j++) {
                if (maxHeap.size()<K) {
                    maxHeap.push(make_pair((double)(A[i])/A[j], make_pair(A[i], A[j])));
                } else {
                   if ((double)A[i]/A[j] < maxHeap.top().first) {
                        maxHeap.pop();
                        maxHeap.push(make_pair((double)A[i]/A[j], make_pair(A[i], A[j])));
                    }
                }
            }
        }
        vector<int> result;
        result.push_back(maxHeap.top().second.first);
        result.push_back(maxHeap.top().second.second);
        return result;
    }
};
