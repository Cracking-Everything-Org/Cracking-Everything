class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (vector<int>& point : points) {
            pq.push(point);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, compare> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            maxHeap.push(points[i]);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
    
    struct compare {
        bool operator()(vector<int>& a, vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        }
    };
};